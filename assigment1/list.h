//
// Created by jinqiu on 19-2-27.
//

#ifndef TESK_LIST_H
#define TESK_LIST_H

#include <iostream>
#include <memory>

using namespace std;

//链表节点
template <class T>
class ListNode
{
public:
    ListNode():value_(nullptr),front(nullptr),next(nullptr){}
    ListNode(const T &value):value_(value),front(nullptr),next(nullptr){}
public:
    T value_;
    ListNode<T> *front;
    ListNode<T> *next;
};

/*******************************************
*                 单向链表                   *
/*******************************************/
template <class T>
class SingleList
{
public:
    SingleList():head_(nullptr),size_(0){}
    ~SingleList();

    //链表大小
    size_t size(){return size_;}
    //链表是否为空
    bool empty(){return size_==0;}
    //获取头结点
    ListNode<T> *get_head(){return head_;}

    //插入节点
    void insert(const int &index,const T &value);
    //删除节点
    T erase(const int &index);
    //修改节点
    void set(const int &index,const T &value);
    //查询节点
    T get(const int &index);

    //打印链表
    void print();

    //单向链表反转
    void reverse();
    //单向链表排序
    void sort();
    //获取链表的中间节点
    ListNode<T> *get_mid_node();
private:
    void quick_sort(ListNode<T> *head,ListNode<T> *end);//快速排序
    void swap(ListNode<T> *p,ListNode<T> *q);//交换两个节点中的值
private:
    ListNode<T> *head_;
    size_t size_;
};

template <class T>
SingleList<T>::~SingleList()
{
    while(head_!= nullptr){
        ListNode<T> *node=head_;
        head_=head_->next;
        delete node;
        node= nullptr;
    }
}

template <class T>
void SingleList<T>::insert(const int &index, const T &value)
{
    if(index<0 || index>size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    ListNode<T> *node=new ListNode<T>(value);

    if(size_==0){
        head_=node;
    } else{
        if(index==0){
            node->next=head_;
            head_=node;
        } else{
            ListNode<T> *cur=head_;
            int i=0;
            while(i<index-1){
                cur=cur->next;
                ++i;
            }
            node->next=cur->next;
            cur->next=node;
        }
    }

    ++size_;
}

template <class T>
T SingleList<T>::erase(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    ListNode<T> *cur=head_;
    T value;
    if(index==0){
        head_=head_->next;
        value=cur->value_;
        delete cur;
        cur= nullptr;
    } else{
        int i=0;
        while(i<index-1){
            cur=cur->next;
            ++i;
        }
        ListNode<T> *temp=cur->next;
        cur->next=temp->next;
        value=temp->value_;
        delete temp;
        temp= nullptr;
    }

    --size_;
    return value;
}

template<class T>
void SingleList<T>::set(const int &index, const T &value)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    if(index==0){
        head_->value_=value;
    } else{
        ListNode<T> *cur=head_;
        int i=0;
        while(i<index){
            cur=cur->next;
            ++i;
        }
        cur->value_=value;
    }
}

template <class T>
T SingleList<T>::get(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    T value;
    if(index==0){
        value=head_->value_;
    } else{
        ListNode<T> *cur=head_;
        int i=0;
        while(i<index){
            cur=cur->next;
            ++i;
        }
        value=cur->value_;
    }

    return value;
}

template <class T>
void SingleList<T>::print()
{
    ListNode<T> *cur=head_;
    while(cur!= nullptr){
        cout<<cur->value_<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

template <class T>
void SingleList<T>::reverse()
{
    if(size_==1){
        return ;
    }

    ListNode<T> *front=head_;
    ListNode<T> *cur=head_->next;
    ListNode<T> *next=cur;
    front->next= nullptr;
    while(next!= nullptr){
        next=cur->next;
        cur->next=front;
        front=cur;
        cur=next;
    }

    head_=front;
}

template <class T>
void SingleList<T>::swap(ListNode<T> *p,ListNode<T> *q)
{
    T temp=p->value_;
    p->value_=q->value_;
    q->value_=temp;
}

template <class T>
void SingleList<T>::quick_sort(ListNode<T> *head, ListNode<T> *end)
{
    if(head==end || head->next==end){
        return ;
    }

    T value=head->value_;
    ListNode<T> *p=head;
    ListNode<T> *q=head->next;
    while( q != end){
        if(value <= q->value_){
            q=q->next;
        }else {
            p=p->next;
            swap(p,q);
            q=q->next;
        }
    }
    swap(head,p);
    quick_sort(head,p);
    quick_sort(p->next,q);
}

template <class T>
void SingleList<T>::sort()
{
    if(head_== nullptr){
        return ;
    }

    ListNode<T> *head=head_;
    ListNode<T> *end= nullptr;
    quick_sort(head,end);
}

template <class T>
ListNode<T> *SingleList<T>::get_mid_node()
{
    ListNode<T> *fast=head_;
    ListNode<T> *slow=head_;

    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


/*******************************************
*                 双向链表                   *
/*******************************************/
template <class T>
class DulList
{
private:
    ListNode<T> *head_;
    size_t size_;
};

#endif //TESK_LIST_H
