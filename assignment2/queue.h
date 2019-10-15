//
// Created by jinqiu on 19-3-3.
//

#ifndef TESK_QUEUE_H
#define TESK_QUEUE_H

#include <iostream>
#include <memory>
#include <pthread.h>

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
public:
    CyclicQueue():capacity_(10),
                  ptr_(shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;})),
                  size_(0),
                  front_(ptr_.get()),
                  back_(ptr_.get()){}
    CyclicQueue(size_t capacity);
    ~CyclicQueue(){}

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
    T *front_;//队列头指针
    T *back_;//队列尾指针
    size_t  size_;//队列中存储元素的个数
    size_t  capacity_;//队列中最大存储数量
};

template <class T>
CyclicQueue<T>::CyclicQueue(size_t capacity)
{
    if(capacity<=0){
        cout<<"queue capacity must >0"<<endl;
        exit(0);
    }

    capacity_=capacity;
    size_=0;
    ptr_=shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;});
    front_=back_=ptr_.get();
}

template <class T>
T CyclicQueue<T>::front()
{
    if(empty()){
        cout<<"CyclicQueue is empty!"<<endl;
        exit(0);
    } else{
        return *front_;
    }
}

template <class T>
T CyclicQueue<T>::back()
{
    if(empty()){
        cout<<"CyclicQueue is empty!"<<endl;
        exit(0);
    } else{
        return *back_;
    }
}

template <class T>
T CyclicQueue<T>::pop()
{
    if(empty()){
        cout<<"CyclicQueue is empty!"<<endl;
        exit(0);
    }

    T value=*front_;
    if(front_==ptr_.get()+capacity_-1){
        front_=ptr_.get();
    }else {
        ++front_;
    }
    --size_;
    return value;
}

template <class T>
void CyclicQueue<T>::expend_capacity(const size_t &new_capacity)
{
    shared_ptr<T> temp(new T[new_capacity],[](T *p){delete[] p;});

    copy(ptr_.get(),ptr_.get()+size_,temp.get());
    ptr_.swap(temp);
    front_ = ptr_.get();
    back_ = ptr_.get()+size_-1;
    temp.reset();
}

template <class T>
void CyclicQueue<T>::push(const T &value)
{
    if(size_==0)
    {
        *back_=value;
    }else if(size_==capacity_){//如果队列已满，需要进行扩容
        capacity_*=2;
        expend_capacity(capacity_);

        ++back_;
        *back_=value;
    }else{
        size_t distance=back_-ptr_.get();//获取尾元素的位置
        size_t index=(distance+1)%capacity_;//获取插入后元素的位置
        back_=ptr_.get()+index;
        *back_=value;
    }

    ++size_;
}

template <class T>
void CyclicQueue<T>::print()
{
    if(size_==0){
        return ;
    }
    size_t i=front_-ptr_.get();
    size_t j=back_-ptr_.get();
    while(true){
        int index=i%capacity_;
        if(index==j){
            break;
        }
        cout<<*(ptr_.get()+index)<<" ";
        ++i;
    }

    cout<<*back_<<endl;
}

/*******************************************
*                 阻塞队列                   *
*******************************************/
template <class T>
class BlockQueue
{
public:
    BlockQueue(const size_t &capacity=100);
    ~BlockQueue();

    //队列是否为空
    bool empty();
    //队列的大小
    size_t size();
    //队列容量大小
    size_t max_size();

    //返回队首元素
    bool front(T &value);
    //返回队尾元素
    bool back(T &value);
    //队首弹出元素
    bool pop(T &value);
    //队尾添加元素
    void push(const T &value);

    //打印队列
    void print();

private:
    T *ptr_;
    T *front_;//队列头指针
    T *back_;//队列尾指针
    size_t  size_;//队列中存储元素的个数
    size_t  capacity_;//队列中最大存储数量

    pthread_mutex_t *mutex_;//互斥锁
    pthread_cond_t *cond_;//条件变量
};

template <class T>
BlockQueue<T>::BlockQueue(const size_t &capacity)
        :capacity_(capacity),size_(0)
{
    ptr_=new T[capacity_];
    front_=back_=ptr_;

    pthread_mutex_init(mutex_, NULL);
    pthread_cond_init(cond_,NULL);
}

template <class T>
BlockQueue<T>::~BlockQueue()
{
    pthread_mutex_lock(mutex_);
    if(ptr_!= nullptr){
        delete[] ptr_;
    }
    pthread_mutex_unlock(mutex_);

    pthread_mutex_destroy(mutex_);
    pthread_cond_destroy(cond_);

    delete mutex_;
    delete cond_;
}

template <class T>
bool BlockQueue<T>::empty()
{
    pthread_mutex_lock(mutex_);
    if(0==size_){
        pthread_mutex_unlock(mutex_);
        return true;
    }
    pthread_mutex_unlock(mutex_);
    return false;
}

template <class T>
size_t BlockQueue<T>::size()
{
    size_t size=0;
    pthread_mutex_lock(mutex_);
    size=size_;
    pthread_mutex_unlock(mutex_);
    return size;
}

template <class T>
size_t BlockQueue<T>::max_size()
{
    size_t capacity=0;
    pthread_mutex_lock(mutex_);
    capacity=capacity_;
    pthread_mutex_unlock(mutex_);
    return capacity;
}

template <class T>
bool BlockQueue<T>::front(T &value)
{
    T front;
    pthread_mutex_lock(mutex_);
    if(size_==0){
        cout<<"BlockQueue is empty!"<<endl;
        pthread_mutex_unlock(mutex_);
        return false;
    }else{
        value=*front_;
    }
    pthread_mutex_unlock(mutex_);

    return true;
}

template <class T>
bool BlockQueue<T>::back(T &value)
{
    T back;
    pthread_mutex_lock(mutex_);
    if(size_==0){
        cout<<"BlockQueue is empty!"<<endl;
        return false;
    }else{
        value=*back_;
    }
    pthread_mutex_unlock(mutex_);

    return true;
}

template <class T>
bool BlockQueue<T>::pop(T &value)
{
    pthread_mutex_lock(mutex_);
    while(size_<=0){
        if(0!=pthread_cond_wait(cond_,mutex_)){
            cout<<"BlockQueue is empty!"<<endl;
            pthread_mutex_unlock(mutex_);
            return false;
        }
    }
    int distance = front_ - ptr_;
    int offset = (distance + 1) % capacity_;
    value=*front_;
    front_=ptr_+offset;
    --size_;
    pthread_mutex_unlock(mutex_);

    return true;
}

template <class T>
void BlockQueue<T>::push(const T &value)
{
    pthread_mutex_lock(mutex_);
    if(size_>=capacity_){
        cout<<"BlockQueue is empty!"<<endl;

        pthread_cond_broadcast(cond_);
        pthread_mutex_unlock(mutex_);
    }else{
        if(size_==0){
            *ptr_=value;
        }else{
            int distance = back_ - ptr_;
            int offset = (distance + 1) % capacity_;
            ptr_[offset]=value;
        }

        ++size_;
        pthread_cond_broadcast(cond_);
        pthread_mutex_unlock(mutex_);
    }
}

template <class T>
void BlockQueue<T>::print()
{
    pthread_mutex_lock(mutex_);

    int i= front_-ptr_;
    int j= back_-ptr_;

    while(true){
        int index=i%capacity_;
        if(index==j){
            break;
        }
        cout<<ptr_[index]<<"==>"<<i<<" ";
        ++i;
    }
    cout<<*back_<<endl;

    pthread_mutex_unlock(mutex_);
}


#endif //TESK_QUEUE_H
