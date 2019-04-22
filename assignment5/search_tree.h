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

    while(p!= nullptr){
        if(theKey<p->value_.first){
            p=p->front;
        }else if(theKey > p->value_.first){
            p=p->next;
        }else{
            return &p->value_;
        }
    }

    return nullptr;
}

template <class K,class E>
void BinarySearchTree<K,E>::insert(const pair<const K, E> &theValue)
{
    //获取根节点
    ListNode<pair<const K,E>> *p=bs_tree_.get_root(),*pp= nullptr;

    //在搜索树中搜索吧该节点
    while(p!= nullptr){
        //保存当前节点父节点
        pp=p;
        if(theValue.first < p->value_.first){
            p=p->front;
        }else if(theValue.first > p->value_.first){
            p=p->next;
        }else{//如果存在搜索树种，直接替换
            p->value_.second=theValue.second;
            return ;
        }
    }

    //创建节点
    ListNode<pair<const K,E>> *newNode=
            new ListNode<pair<const K,E>>(theValue);

    //插入节点
    ListNode<pair<const K,E>> *root;
    if((root=bs_tree_.get_root())!= nullptr){//获取当前节点的子节点，并插入节点
        if(theValue.first<pp->value_.first){
            pp->front=newNode;
        }else{
            pp->next=newNode;
        }
    }else{//如果根节点为空，直接在根节点插入节点
        root=newNode;
    }

    ++bs_tree_.set_size();
}

template <class K,class E>
void BinarySearchTree<K,E>::erase(const K &theKey)
{
    
}

#endif //TESK_SEARCH_TREE_H
