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
template <>
class hash<string>
{
public:
    size_t operator()(const string &key) const
    {
        unsigned long hash_value=0;
        int len=(int)key.length();
        for(int i=0;i<len;++i){
            hash_value=5*hash_value+key.at(i);
        }
    }
};

template <class K,class E>
class ArrayHash
{
public:
    ArrayHash(int divisions);

    //判断是否为空
    bool empty(){return size_==0;}
    //获取哈希表存储数据的大小
    size_t size(){return size_;}
	
    //根据关键字key搜索哈希表中的位置
    int search(const K &key)const;

    //更具关键字key查找数对
    pair<K,E> find(const K &key)const;

    //插入数对
    void insert(const pair<K,E> &thePair);

private:
    vector<pair<K,E>> table_;       //哈希表
    hash<K> hash_;                  //将类型K映射为整数
    size_t size_;                   //哈希表中的数对个数
    int divisions_;                 //哈希函数的除数
};

template <class K,class E>
ArrayHash<K,E>::ArrayHash(int divisions):divisions_(divisions)
{
    size_=0;
    //初始化哈希表
    table_.resize(divisions_);
}

template <class K,class E>
int ArrayHash<K,E>::search(const K &key) const
{
    size_t index=hash_(key);
    index=index%divisions_;

    return 0;
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
    pair<K,E> erase(const K &key);

    //修改关键字key的键值
    void set(const K &key,E &value);

    //根据关键字key搜索哈希表中的位置
    int search(const K &key)const;
    //更具关键字key查找数对
    pair<K,E> find(const K &key)const;
    
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
ListHash<K,E>::ListHash(size_t bucket_size):bucket_size_(bucket_size),
                                            size_(0),hash_()
{
    ptr_=shared_ptr<List>(new List[bucket_size_](),
                          [](List *p){delete[] p;});
}

template <class K,class E>
void ListHash<K,E>::insert(const pair<K, E> &thePair)
{
    size_t index=hash_(thePair.first)%bucket_size_;
    List *slist=ptr_.get()+index;
    slist->insert(0,thePair);
    ++size_;
}

template <class K,class E>
pair<K,E> ListHash<K,E>::erase(const K &key)
{
    size_t index=search(key);
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(slist->get(i).first==key){
            return slist->erase(i);
        }
    }

    cerr<<"未找到键值为 key = "<<key<<" 的数对..."<<endl;
    return nullptr;
}

template <class K,class E>
void ListHash<K,E>::set(const K &key, E &value)
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

    cerr<<"未找到键值为 key = "<<key<<" 的数对,更改数对的键值失败！！！"<<endl;
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

    cerr<<"未找到键值为 key = "<<key<<" 的数对..."<<endl;
    return -1;
}

template <class K,class E>
pair<K,E> ListHash<K,E>::find(const K &key) const
{
    size_t index=hash_(key)%bucket_size_;
    List *slist=ptr_.get()+index;
    for(int i=0;i<slist->size();++i){
        if(key==slist->get(i).first){
            return slist->get(i);
        }
    }

    cerr<<"未找到键值为 key = "<<key<<" 的数对..."<<endl;
    return nullptr;
}

template <class K,class E>
void ListHash<K,E>::print() 
{
    for(int i=0;i<bucket_size_;++i){
        (ptr_.get()+i)->print();
    }
}

#endif //TESK_HASHING_H
