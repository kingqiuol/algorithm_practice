//
// Created by jinqiu on 2019/5/9.
//

#ifndef TESK_B_BTREENODE_H
#define TESK_B_BTREENODE_H

#include <iostream>
using namespace std;

#define RANK 3 //定义树的阶

template <class T>
class BBTreeNode{
public:
    static const int rank_;                 //树的阶
    static const int key_max_;              //关键字最大个数
    static const int key_min_;              //关键字最小个数
    static const int child_max_;            //子节点最大个数
    static const int child_min_;            //子节点最小个数

    bool is_leaf_;                          //是否为叶子节点
    int number_of_key_;                     //关键字的个数
    BBTreeNode<T> *parent_;                 //指向父节点
    BBTreeNode<T> *child_[child_max_];      //存储指向子树的指针
    T element_[key_max_];                     //存储字典数组
public:
    BBTreeNode();
};

template <class T>
const int BBTreeNode<T>::rank_=RANK;
template <class T>
const int BBTreeNode<T>::key_max_=2*BBTreeNode<T>::rank_-1;
template <class T>
const int BBTreeNode<T>::key_min_=BBTreeNode<T>::rank_-1;
template <class T>
const int BBTreeNode<T>::child_max_=BBTreeNode<T>::key_max_-1;
template <class T>
const int BBTreeNode<T>::child_min_=BBTreeNode<T>::key_min_-1;

template <class T>
BBTreeNode<T>::BBTreeNode():is_leaf_(0),number_of_key_(0),parent_(nullptr)
{
    for(int i=0;i<child_max_;++i){
        child_[i]= nullptr;
    }

    for(int j=0;j<key_max_;++j){
        element_[j]=NULL;
    }
}

#endif //TESK_B_BTREENODE_H
