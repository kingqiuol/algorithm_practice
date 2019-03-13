//
// Created by jinqiu on 19-3-12.
//

#ifndef TESK_PRIORITY_QUEUE_H
#define TESK_PRIORITY_QUEUE_H

#include <iostream>
#include <memory>

#include "array.h"

using namespace std;

//最大优先级队列
template <class T>
class PriorityQueue
{
public:
    virtual ~PriorityQueue(){}
    //队列是否为空
    virtual bool empty()= 0;
    //队列元素个数
    virtual int size() = 0;
    //返回队首元素
    virtual T front()=0;
    //出队
    virtual T pop()=0;
    //入队
    virtual void push(const T &value)=0;
};

/*******************************************
*                 大根堆的实现                *
/*******************************************/
template <class T>
class MaxHeap:public PriorityQueue<T>
{
public:
    MaxHeap(size_t capacity=10): heap_(capacity){}
    ~MaxHeap(){}

    //队列是否为空
    bool empty() {return heap_.size()==0;}
    //队列元素个数
    int size() {return heap_.size();}
    //队列的容量
    size_t max_size(){return heap_.max_size();}

    //返回队首元素
    T front();

    //出队
    T pop();

    //入队
    void push(const T &value);

    //打印队列
    void print();
private:
    void adjust_heap();//将堆调整为最大堆
private:
    Array<T> heap_;
};

template <class T>
T MaxHeap<T>::front()
{
    return heap_.get(0);
}

template <class T>
T MaxHeap<T>::pop()
{
    T tmp = heap_.erase(0);
    adjust_heap();
    return tmp;
}

template <class T>
void MaxHeap<T>::adjust_heap()
{
    int len=heap_.size();
    for(int i=len/2-1;i>=0;--i){
        T tmp=heap_.get(i);
        for(int k=2*i+1;k<len;++k){
            if(k+1<len && heap_.get(k)<heap_.get(k+1)){
                ++k;
            }

            if(tmp<heap_.get(k)){
                heap_.replace(i,heap_.get(k));
                i=k;
            }else{
                break;
            }
        }
        heap_.replace(i,tmp);
    }
}

template <class T>
void MaxHeap<T>::push(const T &value)
{
    size_t size=heap_.size();
    heap_.insert(size,value);

    adjust_heap();
}

template <class T>
void MaxHeap<T>::print()
{
    heap_.print();
}

/*******************************************
*                 小根堆的实现                *
/*******************************************/
template <class T>
class MinHeap:public PriorityQueue<T>
{
public:
    MinHeap(size_t capacity=10): heap_(capacity){}
    ~MinHeap(){}

    //队列是否为空
    bool empty() {return heap_.size()==0;}
    //队列元素个数
    int size() {return heap_.size();}
    //队列的容量
    size_t max_size(){return heap_.max_size();}

    //返回队首元素
    T front();

    //出队
    T pop();

    //入队
    void push(const T &value);

    //打印队列
    void print();
private:
    void adjust_heap();//将堆调整为最大堆
private:
    Array<T> heap_;
};

template <class T>
T MinHeap<T>::front()
{
    return heap_.get(0);
}

template <class T>
T MinHeap<T>::pop()
{
    T tmp = heap_.erase(0);
    adjust_heap();
    return tmp;
}

template <class T>
void MinHeap<T>::adjust_heap()
{
    int len=heap_.size();
    for(int i=len/2-1;i>=0;--i){
        T tmp=heap_.get(i);
        for(int k=2*i+1;k<len;++k){
            if(k+1<len && heap_.get(k)>heap_.get(k+1)){
                ++k;
            }

            if(tmp>heap_.get(k)){
                heap_.replace(i,heap_.get(k));
                i=k;
            }else{
                break;
            }
        }
        heap_.replace(i,tmp);
    }
}

template <class T>
void MinHeap<T>::push(const T &value)
{
    size_t size=heap_.size();
    heap_.insert(size,value);

    adjust_heap();
}

template <class T>
void MinHeap<T>::print()
{
    heap_.print();
}

#endif //TESK_PRIORITY_QUEUE_H
