//
// Created by jinqiu on 19-3-6.
//

#ifndef TESK_HASHING_H
#define TESK_HASHING_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "list.h"

using namespace std;

/*******************************************
*                哈希表的数组实现              *
/*******************************************/
template <class K,class E>
class ArrayHash
{
public:
    ArrayHash(int divisions);
    ~ArrayHash();

    //判断是否为空
    bool empty(){return size_==0;}
    //获取哈希表存储数据的大小
    size_t size(){return size_;}

    //插入数对
    void insert(const pair<K,E> &thePair);

    //删除数对
    void erase(const K &key);

    //修改关键字key的键值
    void set(const K &key,const E &value);

    //根据关键字key搜索哈希表中的位置
    int search(const K &key)const;
    //更具关键字key查找数对
    pair<K,E> *find(const K &key)const;

    //打印哈希表
    void print();

private:
    pair<K,E> **table_; //哈希表
    hash<K> hash_;      //将类型K映射为整数
    size_t size_;       //哈希表中的数对个数
    int bucket_size_;   //哈希函数的除数
};

template <class K,class E>
ArrayHash<K,E>::ArrayHash(int bucket_size):bucket_size_(bucket_size)
{
    size_=0;
    //初始化哈希表
    table_=new pair<K,E>*[bucket_size_];
    for(int i=0;i<bucket_size_;++i){
        table_[i]=NULL;
    }
}

template <class K,class E>
ArrayHash<K,E>::~ArrayHash()
{
    for(int i=0;i<bucket_size_;++i){
        if(table_[i]!=NULL){
            delete table_[i];
        }
    }

    delete[] table_;
}

template <class K,class E>
void ArrayHash<K,E>::insert(const pair<K, E> &thePair)
{
    size_t index=search(thePair.first);

    if(table_[index]==NULL){
        table_[index]=new pair<K,E>(thePair);
        ++size_;
    }else if(table_[index]->first==thePair.first){
        table_[index]->second=thePair.second;
    }else{
        cerr<<"array hush is full!"<<endl;
        exit(0);
    }
}

template <class K,class E>
void ArrayHash<K,E>::erase(const K &key)
{
    size_t src_index=hash_(key)%bucket_size_;
    int index=search(key);

    if(table_[index]==NULL || table_[index]->first!=key){
        return ;
    }else{
        pair<K,E> tmp(*table_[index]);

        delete table_[index];
        table_[index]=NULL;


    }
}

template <class K,class E>
void ArrayHash<K,E>::set(const K &key, const E &value)
{
    size_t index=search(key);

    if(table_[index]==NULL){
        insert(make_pair(key,value));
    }else if(table_[index]->first==key){
        table_[index]->second=value;
    } else{
        cerr<<"array hush don't has this pair..."<<endl;
        exit(0);
    }
}

template <class K,class E>
int ArrayHash<K,E>::search(const K &key) const
{
    size_t index=hash_(key)%bucket_size_;

    int j=index;
    do{
        if(table_[j]==NULL || table_[j]->first==key){
            return j;
        }
        j=(j+1)%bucket_size_;
    }while(j!=index);

    return j;
}

template <class K,class E>
pair<K,E> *ArrayHash<K,E>::find(const K &key) const
{
    size_t index=search(key);

    if(table_[index]==NULL){
        return NULL;
    }else{
        return table_[index];
    }
}

template <class K,class E>
void ArrayHash<K,E>::print()
{
    for(int i=0;i<bucket_size_;++i){
        cout<<i<<":";
        if(table_[i]!=NULL){
            cout<<table_[i]->first<<"->"<<table_[i]->second;
        }
        cout<<endl;
    }
}

/*******************************************
*                哈希表的链表实现              *
/*******************************************/
template <class K,class E>
class ListHash
{
public:
    ListHash(size_t bucket_size);
    ~ListHash(){}

    //判断是否为空
    bool empty(){return size_==0;}
    //获取哈希表存储数据的大小
    size_t size(){return size_;}

    //插入数对
    void insert(const pair<K,E> &thePair);

    //删除数对
    void erase(const K &key);

    //修改关键字key的键值
    void set(const K &key,const E &value);

    //根据关键字key搜索哈希表中的位置
    int search(const K &key)const;
    //更具关键字key查找数对
    pair<K,E> *find(const K &key)const;
    
    //打印哈希表
    void print();
private:
    typedef SingleList<pair<K,E>> List;
    shared_ptr<List> ptr_;
    size_t bucket_size_;
    size_t size_;
    hash<K> hash_;
};

template <class K,class E>
ListHash<K,E>::ListHash(size_t bucket_size):bucket_size_(bucket_size), size_(0)
{
    ptr_=shared_ptr<List>(new List[bucket_size_](),
                          [](List *p){delete[] p;});
}

template <class K,class E>
void ListHash<K,E>::insert(const pair<K, E> &thePair)
{
    size_t index=hash_(thePair.first)%bucket_size_;

    List *slist=ptr_.get()+index;

    for(int i=0;i<slist->size();++i){
        if(slist->get(i).first==thePair.first){
            slist->set(i,thePair);
            return;
        }
    }
    slist->insert(0,thePair);
    ++size_;
}

template <class K,class E>
void ListHash<K,E>::erase(const K &key)
{
    size_t index=search(key);
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(slist->get(i).first==key){
            slist->erase(i);
            return ;
        }
    }

    cerr<<"Don't find key = "<<key<<" pair..."<<endl;
    return ;
}

template <class K,class E>
void ListHash<K,E>::set(const K &key,const E &value)
{
    pair<K,E> tmp(key,value);
    size_t index=hash_(key)%bucket_size_;
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(slist->get(i).first==key){
            slist->set(i,tmp);
            return ;
        }
    }

    cerr<<"Don't find key = "<<key<<" pair,failed to change key values of pairs ！！！"<<endl;
}

template <class K,class E>
int ListHash<K,E>::search(const K &key) const
{
    size_t index=hash_(key)%bucket_size_;
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(key==slist->get(i).first){
            return index;
        }
    }

    return -1;
}

template <class K,class E>
pair<K,E> *ListHash<K,E>::find(const K &key) const
{
    size_t index=hash_(key)%bucket_size_;
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(key==slist->get(i).first){
            return &slist->get(i);
        }
    }

    cerr<<"未找到键值为 key = "<<key<<" 的数对..."<<endl;
    return NULL;
}

template <class K,class E>
void ListHash<K,E>::print() 
{
    for(int i=0;i<bucket_size_;++i){
        List *cur=ptr_.get()+i;
        if(cur->size()==0){
            continue;
        }
        cout<<i<<":";
        for(int j=0;j<cur->size();++j){
            pair<K,E> tmp=cur->get(j);
            cout<<tmp.first<<"->"<<tmp.second<<",";
        }
        cout<<endl;
    }
}

#endif //TESK_HASHING_H
