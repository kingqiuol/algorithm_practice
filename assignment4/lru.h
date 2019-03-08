//
// Created by jinqiu on 2019/3/8.
//

#ifndef TESK_LRU_H
#define TESK_LRU_H

#include "hashing.h"
#include "list.h"

#include <iostream>


using namespace std;


class LRUcache
{
public:
    LRUcache(size_t bucket_size,size_t capacity=50): bucket_size_(bucket_size),
                                                     capacity_(capacity),
                                                     size_(0),
                                                     hash_(bucket_size),
                                                     dul_list_(){}
    size_t size(){return size_;}
    size_t max_size(){return capacity_;}

    void put_cache(const pair<string,int> &thepair);
    void print();

private:
    ListHash<string,int> hash_;
    DulList<pair<string,int>*> dul_list_;
    size_t  size_;
    size_t bucket_size_;
    size_t capacity_;
};

void LRUcache::put_cache(const pair<string,int> &thepair)
{
    int index=hash_.search(thepair.first);
    if(-1==index){//如果不存在该数据
        //如果超过容量
        if(size_>=capacity_){
            //获取最后一条数据的地址，并在双向链表和哈希表中删除该数据
            pair<string,int> *back=dul_list_.dul_erase(size_-1);
            hash_.erase(back->first);
            --size_;
        }

        //向哈希表中插入数据
        hash_.insert(thepair);

        //获取数据的首地址
        pair<string,int> *tmp=hash_.find(thepair.first);

        //向双向链表中插入数据的首地址
        dul_list_.dul_insert(0,tmp);

        ++size_;
    }else{//如果已存在该数据
        //返回该数据的首地址
        pair<string,int> *tmp=hash_.find(thepair.first);

        //在双向链表中获取该数据首地址位置
        int index=dul_list_.get_index(tmp);

        //删除该数据首地址
        dul_list_.dul_erase(index);

        //向链表的头部插入数据数据首地址
        dul_list_.dul_insert(0,tmp);

        //向哈希表中插入数据
        hash_.insert(thepair);
    }
}

void LRUcache::print()
{
    hash_.print();

    for(int i=0;i<dul_list_.size();++i){
        pair<string,int> *temp=dul_list_.get_node(i)->value_;
        cout<<temp->first<<"->"<<temp->second<<",";
    }
    cout<<endl;
}

#endif //TESK_LRU_H
