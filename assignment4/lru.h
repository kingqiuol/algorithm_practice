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

    void put_cache(const pair<string, ListNode<int>*> &thepair);
    void get_cache();

private:
    ListHash<string,DulList<int>*> hash_;
    DulList<int> dul_list_;
    size_t  size_;
    size_t bucket_size_;
    size_t capacity_;
};

void LRUcache::put_cache(const pair<string, ListNode<int>*> &thepair)
{
    int index=hash_.search(thepair.first);
    ListNode<int> *node=new ListNode(thepair.second->value_);
    pair<string,ListNode<int>*> cur_pair=make_pair(thepair.first,node);

}

#endif //TESK_LRU_H
