//
// Created by jinqiu on 19-4-21.
//

#ifndef TESK_SEARCH_TREE_H
#define TESK_SEARCH_TREE_H

#include <iostream>

#include "utils.h"
#include "binary_tree.h"

using namespace std;

template<class K,class E>
class BSTree:public Dictionary<K,E>
{
public:
    //关键字按升序输出
    virtual void ascend()=0;
};

/*******************************************
*                二叉搜索树的实现              *
/*******************************************/
template <class K,class E>
class BinarySearchTree:public BSTree<K,E>
{
public:
    BinarySearchTree():bs_tree_(){}
    ~BinarySearchTree(){}

    //判断字典是否为空
    bool empty() const{return bs_tree_.size()==0;}

    //返回字典的大小
    int size() const{return bs_tree_.size();}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend(){bs_tree_.inOrder();}
private:
    ListBTree<pair<const K,E>> bs_tree_;
};

template <class K,class E>
pair<const K, E>* BinarySearchTree<K,E>::find(const K &theKey)
{
    ListNode<pair<const K,E>> *p=bs_tree_.get_root();

    if(p== nullptr){
        exit(0);
    }

    if(p->value_.first==theKey){
        return &(p->value_);
    }



}

#endif //TESK_SEARCH_TREE_H
