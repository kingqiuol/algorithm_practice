//
// Created by jinqiu on 19-3-3.
//

#ifndef TESK_QUEUE_H
#define TESK_QUEUE_H

#include <iostream>
#include <memory>

#include "list.h"

using namespace std;

//队列的基类
template <class T>
class Queue
{
public:
    virtual  ~Queue(){}
    //队列是否为空
    virtual bool empty() = 0;
    //队列的大小
    virtual size_t size() =0;
    //返回队首元素
    virtual  T front() = 0;
    //返回队尾元素
    virtual T back() = 0;
    //队首弹出元素
    virtual T pop() = 0;
    //队尾添加元素
    virtual void push(const T &value) = 0;
};

/*******************************************
*               队列数组描述                 *
*******************************************/
template <class T>
class ArrayQueue:public Queue<T>
{
public:
    ArrayQueue()
            :capacity_(10),
             ptr_(shared_ptr<T>(new T[10],[](T *p){delete[] p;})),
             size_(0){}
    ArrayQueue(const size_t &capacity);
    ~ArrayQueue(){}

    //队列是否为空
    bool empty(){return size_==0;}
    //队列的大小
    size_t size(){return size_;}
    //队列容量大小
    size_t max_size(){return capacity_;}

    //返回队首元素
    T front();
    //返回队尾元素
    T back();
    //队首弹出元素
    T pop();
    //队尾添加元素
    void push(const T &value);

    //打印队列
    void print();
private:
    void expend_capacity(const size_t &new_capacity);//动态扩容
private:
    shared_ptr<T> ptr_;
    size_t size_;
    size_t capacity_;
};

template <class T>
ArrayQueue<T>::ArrayQueue(const size_t &capacity)
{
    if(capacity_<=0){
        cout<<"queue capacity must >0"<<endl;
        exit(0);
    }

    capacity_=capacity;
    ptr_=shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;});
    size_=0;
}

template <class T>
T ArrayQueue<T>::front()
{
    return *ptr_.get();
}

template <class T>
T ArrayQueue<T>::back()
{
    return *(ptr_.get()+size_-1);
}

template <class T>
T ArrayQueue<T>::pop()
{
    T value=*ptr_.get();
    copy(ptr_.get()+1,ptr_.get()+size_,ptr_.get());
    --size_;

    return value;
}

template <class T>
void ArrayQueue<T>::expend_capacity(const size_t &new_capacity)
{
    shared_ptr<T> temp(new T[new_capacity],[](T *p){delete[] p;});
    copy(ptr_.get(),ptr_.get()+size_,temp.get());
    ptr_.swap(temp);
    temp.reset();
}

template <class T>
void ArrayQueue<T>::push(const T &value)
{
    if(size_+1>capacity_){
        capacity_*=2;
        expend_capacity(capacity_);
    }

    *(ptr_.get()+size_)=value;
    ++size_;
}

template <class T>
void ArrayQueue<T>::print()
{
    for(int i=0;i<size_;++i){
        cout<<*(ptr_.get()+i)<<" ";
    }
    cout<<endl;
}

/*******************************************
*               队列链表描述                 *
*******************************************/
template <class T>
class ListQueue:public Queue<T>,
                public SingleList<T>
{
public:
    ListQueue():head_(SingleList<T>()){};
    ~ListQueue(){};

    //队列是否为空
    bool empty() {return head_.empty();}
    //队列的大小
    size_t size(){return head_.size();}

    //返回队首元素
    T front();
    //返回队尾元素
    T back();
    //队首弹出元素
    T pop();
    //队尾添加元素
    void push(const T &value);

    //打印队列
    void print();
private:
    SingleList<T> head_;
};

template <class T>
T ListQueue<T>::front()
{
    return head_.get(0);
}

template <class T>
T ListQueue<T>::back()
{
    return head_.get(size()-1);
}

template <class T>
T ListQueue<T>::pop()
{
    return head_.erase(0);
}

template <class T>
void ListQueue<T>::push(const T &value)
{
    head_.insert(size(),value);
}

template <class T>
void ListQueue<T>::print()
{
    head_.print();
}


/*******************************************
*                 循环队列                   *
*******************************************/
template <class T>
class CyclicQueue:public Queue<T>
{
    
};

#endif //TESK_QUEUE_H
