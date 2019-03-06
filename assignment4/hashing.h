//
// Created by jinqiu on 19-3-6.
//

#ifndef TESK_HASHING_H
#define TESK_HASHING_H

#include <iostream>
#include <string>
#include <vector>

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
    size_t size_;                      //哈希表中的数对个数
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

    if(table_[index]==NULL){

    }
}



#endif //TESK_HASHING_H
