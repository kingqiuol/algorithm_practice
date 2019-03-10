//
// Created by jinqiu on 19-3-10.
//

#ifndef TESK_BINARY_TREE_H
#define TESK_BINARY_TREE_H

#include <iostream>
#include <memory>

using namespace std;

template <class T>
class BTree
{
public:
    virtual ~BTree(){}
    virtual bool empty() const =0;
    virtual size_t size() const=0;
    //前序遍历
    virtual void preOrder(void(*) (T*))=0;
    //中序遍历
    virtual void inOrder(void(*) (T*))=0;
    //后序遍历
    virtual void postOrder(void(*) (T*))=0;
    //层次遍历
    virtual void levelOrder(void(*) (T*))=0;
};

/*******************************************
*                二叉树的数组实现              *
/*******************************************/
template <class T>
class ArrayBTree:public BTree<T>
{
public:
    ArrayBTree(const size_t &capacity=10):capacity_(capacity), size_(0),
                                    ptr_(shared_ptr<T>(new T[capacity_](),
                                                       [](T *p){delete[] p;})){}
    ~ArrayBTree(){}

    //二叉树元素的数量
    size_t size() const{return size_;}
    //二叉树是否为空
    bool empty() const{return size_==0;};

    //向二叉树中插入元素
    void insert(const T &value);

    //删除二叉树中的元素
    T erase(const int &index);

    //修改二叉树中的元素
    void set(const T &index,const T &value);

    //查找二叉树中的元素
    T get(const int &index);

    //打印二叉树
    void print();
private:
    shared_ptr<T> ptr_;//存储二叉树数的数组
    size_t size_;//二叉树元素的大小
    size_t capacity_;//二叉树的容量
};

template <class T>
void ArrayBTree<T>::insert(const T &value)
{
    if(this->empty()){
        *ptr_.get()=value;
    }else{

    }

    ++size_;
}

/*******************************************
*                二叉树的链表实现              *
/*******************************************/

#endif //TESK_BINARY_TREE_H
