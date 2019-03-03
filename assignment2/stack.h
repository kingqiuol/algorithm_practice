//
// Created by jinqiu on 19-3-2.
//

#ifndef TESK_STACK_H
#define TESK_STACK_H

#include <iostream>
#include <memory>

#include "list.h"

using namespace std;

//栈的基类
template <class T>
class Stack
{
public:
    virtual ~Stack(){}
    //判断栈是否为空
    virtual bool empty() = 0;
    //栈中元素的大小
    virtual size_t size() = 0;
    //获取栈顶元素
    virtual T top() = 0;
    //弹出栈顶元素
    virtual T pop() = 0;
    //入栈
    virtual void push(const T &value)=0;
};

/*******************************************
*               栈的数组描述                 *
*******************************************/
template <class T>
class ArrayStack:public Stack<T>
{
public:
    ArrayStack(size_t capacity);
    ~ArrayStack(){}

    //判断栈是否为空
    bool empty(){return size_==0;}
    //栈中元素的大小
    size_t size(){return size_;}

    //获取栈顶元素
    T top();
    //弹出栈顶元素
    T pop();
    //入栈
    void push(const T &value);

    //打印栈
    void print();
private:
    void expend_capacity(const size_t &new_capacity);//动态扩容
private:
    shared_ptr<T> ptr_;
    size_t capacity_;
    size_t size_;
};

template <class T>
ArrayStack<T>::ArrayStack(size_t capacity):capacity_(capacity)
{
    if(capacity_<=0){
        cout<<"stack capacity must >0"<<endl;
        exit(0);
    }

    size_=0;
    ptr_=shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;});
}

template <class T>
T ArrayStack<T>::top()
{
    return ptr_.get()[size_-1];
}

template <class T>
T ArrayStack<T>::pop()
{
    --size_;
    return ptr_.get()[size_];
}

template <class T>
void ArrayStack<T>::expend_capacity(const size_t &new_capacity)
{
    shared_ptr<T> temp(new T[new_capacity],[](T *p){delete[] p;});
    copy(ptr_.get(),ptr_.get()+size_,temp.get());
    ptr_.swap(temp);
    temp.reset();
}

template <class T>
void ArrayStack<T>::push(const T &value)
{
    //如果栈已满，进行扩容
    if(size_==capacity_){
        capacity_*=2;
        expend_capacity(capacity_);
    }

    ++size_;
    ptr_.get()[size_-1]=value;
}

template <class T>
void ArrayStack<T>::print()
{
    for(int i=0;i<size_;++i){
        cout<<ptr_.get()[i]<<" ";
    }
    cout<<endl;
}

/*******************************************
*               栈的数组描述                 *
*******************************************/
template <class T>
class ListStack:public Stack<T>,
                public SingleList<T>
{
public:
    ListStack():top_(SingleList<T>()){}
    ~ListStack(){}

    //判断栈是否为空
    bool empty(){return top_.empty();}
    //栈中元素的大小
    size_t size(){return top_.size();}

    //获取栈顶元素
    T top();
    //弹出栈顶元素
    T pop();
    //入栈
    void push(const T &value);

    //打印栈
    void print();
private:
    SingleList<T> top_;
};

template <class T>
T ListStack<T>::top()
{
    if(empty()){
        cout<<"stack is empty!"<<endl;
        exit(0);
    }

    return top_.get(0);
}

template <class T>
T ListStack<T>::pop()
{
    return top_.erase(0);
}

template <class T>
void ListStack<T>::push(const T &value)
{
    top_.insert(0,value);

}

template <class T>
void ListStack<T>::print()
{
    top_.print();
}

#endif //TESK_STACK_H
