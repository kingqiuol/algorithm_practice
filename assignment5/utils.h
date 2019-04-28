//
// Created by jinqiu on 19-4-21.
//

#ifndef TESK_UTILS_H
#define TESK_UTILS_H

#include <iostream>
using namespace std;

//二叉树节点的定义
template <class T>
class BTreeNode
{
public:
    T element_;             //存储的元素
    BTreeNode<T> *left_;    //指向左子树
    BTreeNode<T> *right_;   //指向右子树
    BTreeNode<T> *parent_;  //指向父节点
public:
    BTreeNode(){left_=right_=parent_= nullptr;}

    BTreeNode(const BTreeNode<T> &theClass)
            :element_(theClass.element_),
             left_(theClass.left_),
             right_(theClass.right_),
             parent_(theClass.parent_){}

    BTreeNode(const T &theElement):element_(theElement),
                                   left_(nullptr),right_(nullptr),parent_(nullptr){}

    BTreeNode(const T &theElement,BTreeNode<T> *left,BTreeNode<T> *right)
            :element_(theElement),left_(left),right_(right),parent_(nullptr){}

    BTreeNode(const T &theElement,BTreeNode<T> *left,BTreeNode<T> *right,BTreeNode<T> *parent)
            :element_(theElement),left_(left),right_(right),parent_(parent){}
};

//索引二叉搜索树节点
template <class T>
class IndexBTreeNode
{
public:
    T element_;                     //存储的元素
    IndexBTreeNode<T> *left_;       //指向左子树
    IndexBTreeNode<T> *right_;      //指向右子树
    IndexBTreeNode<T> *parent_;     //指向父节点
    int left_size_;                 //当前节点左子树节点的个数

    IndexBTreeNode():left_size_(0){ left_=right_=parent_= nullptr;}
    IndexBTreeNode(const IndexBTreeNode<T> &theClass):element_(theClass.element_),
                                                      left_(theClass.left_),
                                                      right_(theClass.right_),
                                                      parent_(theClass.parent_) ,
                                                      left_size_(theClass.left_size_){}

    IndexBTreeNode(const T &theElement):element_(theElement),
                                        left_(nullptr),right_(nullptr),parent_(nullptr),
                                        left_size_(0){}

    IndexBTreeNode(const T &theElement,IndexBTreeNode<T> *left,IndexBTreeNode<T> *right,int left_size)
            :element_(theElement),
             left_(left),right_(right),parent_(nullptr),
             left_size_(left_size_){}

    IndexBTreeNode(const T &theElement,
                   IndexBTreeNode<T> *left,
                   IndexBTreeNode<T> *right,
                   IndexBTreeNode<T> *parent,
                   int left_size):element_(theElement),
                                  left_(left),right_(right),parent_(parent),
                                  left_size_(left_size_){}
};

//二叉搜索树字典的基类
template<class K, class E>
class Dictionary
{
public:
    virtual ~Dictionary() {}
    //判断字典是否为空
    virtual bool empty() const = 0;
    //返回字典的大小
    virtual int size() const = 0;
    //搜索字典
    virtual pair<const K, E>* find(const K&) = 0;
    //删除字典
    virtual void erase(const K&) = 0;
    //插入字典
    virtual void insert(const pair<const K, E>&) = 0;
};

#endif //TESK_UTILS_H
