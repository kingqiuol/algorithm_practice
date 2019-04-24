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
    BinarySearchTree():phead_(nullptr),size_(0){}
    ~BinarySearchTree(){}

    //判断字典是否为空
    bool empty() const{return size_==0;}
    //返回字典的大小
    int size() const{return size_;}
    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend();
private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t  size_;
};

template <class K,class E>
pair<const K, E>* BinarySearchTree<K,E>::find(const K &theKey)
{
    BTreeNode<pair<const K,E>> *p= phead_;

    while(p!= nullptr){
        if(theKey<p->element_.first){
            p=p->left_;
        }else if(theKey > p->element_.first){
            p=p->right_;
        }else{
            return &p->element_;
        }
    }

    return nullptr;
}

template <class K,class E>
void BinarySearchTree<K,E>::insert(const pair<const K, E> &theValue)
{
    //获取根节点
    BTreeNode<pair<const K,E>> *p=phead_,*pp= nullptr;

    //在搜索树中搜索吧该节点
    while(p!= nullptr){
        //保存当前节点父节点
        pp=p;
        if(theValue.first < p->element_.first){
            p=p->left_;
        }else if(theValue.first > p->element_.first){
            p=p->right_;
        }else{//如果存在搜索树种，直接替换
            p->element_.second=theValue.second;
            return ;
        }
    }

    //创建节点
    BTreeNode<pair<const K,E>> *newNode=
            new BTreeNode<pair<const K,E>>(theValue);

    //插入节点
    if(phead_!= nullptr){//获取当前节点的子节点，并插入节点
        if(theValue.first<pp->element_.first){
            pp->left_=newNode;
        }else{
            pp->right_=newNode;
        }
    }else{//如果根节点为空，直接在根节点插入节点
        phead_=newNode;
    }

    ++size_;
}

template <class K,class E>
void BinarySearchTree<K,E>::erase(const K &theKey)
{
    //查找关键字
    BTreeNode<pair<const K,E>> *p=phead_,
            *pp= nullptr;

    while(p!= nullptr && p->element_.first!=theKey){
        pp=p;
        if(theKey < p->element_.first){
            p=p->left_;
        } else{
            p=p->right_;
        }
    }
    //如果不存在关键字thekey
    if(p== nullptr){
        return ;
    }

    //如果p有两个非空子树
    if(p->left_!= nullptr && p->right_!= nullptr){
        //搜索p的走左子树最大节点
        BTreeNode<pair<const K,E>> *max_child=p->left_,
                *p_max= p;
        while(max_child->right_!= nullptr){
            p_max=max_child;
            max_child=max_child->right_;
        }

        //将最大元素移动到p(注意key为const，不能直接赋值)
        BTreeNode<pair<const K,E>> *q=new BTreeNode<pair<const K,E>>
                (max_child->element_,p->left_,p->right_);

        if(pp== nullptr){
            phead_=q;
        }else if(p==pp->left_){
            pp->left_=q;
        }else{
            pp->right_=q;
        }
        if(p_max==p) pp=q;
        else pp=p_max;

        delete p;
        p=max_child;
    }

    //如果p最多只有一个孩子
    BTreeNode<pair<const K,E>> *c;
    if(p->left_!= nullptr){
        c=p->left_;
    } else{
        c=p->right_;
    }

    //删除p
    if(p==phead_){
        phead_=c;
    } else{
        if(p==pp->left_){
            pp->left_=c;
        } else{
            pp->right_=c;
        }
    }

    --size_;
    delete p;
}

#endif //TESK_SEARCH_TREE_H
