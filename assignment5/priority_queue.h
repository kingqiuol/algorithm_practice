//
// Created by jinqiu on 19-3-12.
//

#ifndef TESK_PRIORITY_QUEUE_H
#define TESK_PRIORITY_QUEUE_H

#include <iostream>
#include <memory>

using namespace std;

//最大优先级队列
template <class T>
class MaxPriorityQueue
{
public:
    ~MaxPriorityQueue(){}
    //队列是否为空
    virtual bool empty() const = 0;
    //队列元素个数
    virtual int size() const = 0;
    //返回队首元素
    virtual const T &top()=0;
    //出队
    virtual void pop()=0;
    //入队
    virtual void push(const T &value)=0;
};

/*******************************************
*                 大根堆的实现                *
/*******************************************/
template <class T>
class MaxHeap:public MaxPriorityQueue<T>
{
public:
    MaxHeap();
    ~MaxHeap();

    //队列是否为空
    bool empty() const;
    //队列元素个数
    int size() const;

    //返回队首元素
    const T &top();

    //出队
    void pop();

    //入队
    void push(const T &value);
private:
    shared_ptr<T> ptr_;
    size_t size_;
    size_t capacity_;
};


#endif //TESK_PRIORITY_QUEUE_H
