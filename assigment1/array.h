//
// Created by jinqiu on 19-2-26.
//

#ifndef TESK_ARRAY_H
#define TESK_ARRAY_H

#include <iostream>
#include <memory>
#include <math.h>
#include <algorithm>

using namespace std;

/*******************************************
*                   数组                   *
/*******************************************/
template <class T>
class Array{
public:
    Array():
            capacity_(10),
            ptr_(new T[capacity_],[](T *p){delete[] p;}),
            size_ (0){}
    Array(size_t capacity)
            :capacity_(capacity),
             ptr_(new T[capacity_],[](T *p){delete[] p;}),
             size_(0){}

    Array(const Array<T> &other);

    Array(const Array &other);

    ~Array(){}

    //获取数组存储元素大小
    size_t &size(){return size_;}
    //判断是否为空
    bool empty(){return size_==0;}
    //获取数组容器的承载能力大小
    size_t &max_size(){return capacity_;}

    //插入元素
    void insert(const int &index,const T &value);
    //删除元素
    T erase(const int &index);
    //修改指定位置元素
    void replace(const int &index,T &value);
    //获取元素
    T get(const int &index){return *(ptr_.get()+index);}
    //打印数组
    void print();
public:
    void expend_capacity();//动态扩容

    size_t capacity_;
    size_t size_;
    shared_ptr<T> ptr_;
};

template <class T>
Array<T>::Array(const Array &other)
{
    this->size_=other.size_;
    this->capacity_=other.capacity_;
    this->ptr_=shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;});
    copy(other.ptr_.get(),other.ptr_.get()+other.size_,ptr_.get());
}

template <class T>
void Array<T>::expend_capacity()
{
    shared_ptr<T> temp(new T(capacity_));

    if(size_==0){
        return ;
    } else{
        copy(ptr_.get(),ptr_.get()+size_-1,temp.get());
        ptr_.swap(temp);
        temp.reset();
        return ;
    }
}

template <class T>
void Array<T>::insert(const int &index,const T &value)
{
    if(index<0){
        cout<<"index out of range,index < 0"<<endl;
        exit(0);
    }

    if(size_+1>capacity_){
        capacity_*=2;
        expend_capacity();
    }

    if(index>=size_){
        *(ptr_.get()+size_)=value;
    } else{
        copy(ptr_.get()+index,ptr_.get()+size_,ptr_.get()+index+1);
        *(ptr_.get()+index)=value;
    }
    ++size_;
}

template <class T>
T Array<T>::erase(const int &index)
{
    if(index>=size_ || index<0){
        cout<<"index out of range,index < 0 or index < size"<<endl;
        exit(0);
    }
    if(index == size_-1){
        --size_;
        return *(ptr_.get()+index);
    }else{
        T temp=*(ptr_.get()+index);
        copy(ptr_.get()+index+1,ptr_.get()+size_,ptr_.get()+index);
        --size_;
        return temp;
    }
}

template <class T>
void Array<T>::replace(const int &index, T &value)
{
    if(index>=size_ || index<0){
        cout<<"index out of range,index < 0 or index < size"<<endl;
        exit(0);
    }

    *(ptr_.get()+index)=value;
}

template <class T>
void Array<T>::print()
{
    for(int i=0;i<size_;++i){
        cout<<this->get(i)<<" ";
    }
    cout<<endl;
}

/*******************************************
*               有序数组                    *
/*******************************************/
template <class T>
class OrderedArray:public Array<T>
{
public:
    OrderedArray();
    OrderedArray(size_t capacity):Array<T>(capacity){}
    OrderedArray(OrderedArray &other);

    //获取数组存储元素大小
    size_t &size(){return Array<T>::size();}
    //获取数组容器的承载能力大小
    size_t &max_size(){return Array<T>::max_size();}
    //判断是否为空
    bool empty(){return Array<T>::empty();}
    //获取指向有序数组首地址的指针
    T *get(){return Array<T>::ptr_.get();}

    //向顺序数组中添加元素
    void ordered_insert(const T &value);
    //顺序数组中删除元素
    T ordered_erase(const T &index);
    //向顺序数组中设置元素
    void ordered_set(const int &index,const T &value);

    //打印数组
    void print();
};

template <class T>
OrderedArray<T>::OrderedArray()
{
    Array<T>::capacity_=10;
    Array<T>::size_=0;
    Array<T>::ptr_=shared_ptr<T>(new T[Array<T>::capacity_],[](T *p){delete[] p;});
}

template <class T>
OrderedArray<T>::OrderedArray(OrderedArray<T> &other)
{
    Array<T>::size_=other.size_;
    Array<T>::capacity_=other.capacity_;
    Array<T>::ptr_=shared_ptr<T>(new T[Array<T>::capacity_],[](T *p){delete[] p;});
    copy(other.ptr_.get(),other.ptr_.get()+other.size_,Array<T>::ptr_.get());
}

template <class T>
void OrderedArray<T>::ordered_insert(const T &value)
{
    int pos=0;
    if(Array<T>::size_==0){
        Array<T>::insert(0,value);
    } else if(Array<T>::size_+1 > Array<T>::capacity_){
        cout<<"element numbers out of capacity"<<endl;
        exit(0);
    }else{
       while(pos < Array<T>::size_){
           if(*(Array<T>::ptr_.get()+pos) >= value){
               Array<T>::insert(pos,value);
               break;
           }
           ++pos;
       }
        if(pos == Array<T>::size_ ){
            Array<T>::insert(Array<T>::size_,value);
        }
    }
}

template <class T>
T OrderedArray<T>::ordered_erase(const T &index)
{
    return erase(index);
}

template <class T>
void OrderedArray<T>::ordered_set(const int &index, const T &value)
{
    ordered_erase(index);
    ordered_insert(value);
}

template <class T>
void OrderedArray<T>::print()
{
    Array<T>::print();
}


#endif //TESK_ARRAY_H
