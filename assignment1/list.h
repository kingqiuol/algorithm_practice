//
// Created by jinqiu on 19-2-27.
//

#ifndef TESK_LIST_H
#define TESK_LIST_H

#include <iostream>
#include <memory>
#include "list.h"


using namespace std;

//链表节点
template <class T>
class ListNode
{
public:
    ListNode():value_(NULL),front(nullptr),next(nullptr){}
    ListNode(const T &value):value_(value),front(nullptr),next(nullptr){}
    ListNode(const T &value, ListNode<T> *left, ListNode<T> *right): value_(value),
                                                                     front(left),
                                                                     next(right){}
    ListNode(const ListNode<T> &theNode): value_(theNode.value_),
                                          front(nullptr),
                                          next(nullptr){}
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
    T &get(const int &index);
    //获取链表值对应下标
    int get_index(const T &value);

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
T &SingleList<T>::get(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    T value;
    if(index==0){
        return head_->value_;
    } else{
        ListNode<T> *cur=head_;
        int i=0;
        while(i<index){
            cur=cur->next;
            ++i;
        }
        return cur->value_;
    }
}

template <class T>
int SingleList<T>::get_index(const T &value)
{
    for(int i=0;i<size_;++i){
        if(get(i)==value){
            return i;
        }
    }

    return -1;
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
*               单向循环链表                  *
/*******************************************/
template <class T>
class CycSingleList{
public:
    CycSingleList():head_(nullptr),size_(0){}
    ~CycSingleList();

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
    T &get(const int &index);
    //获取链表值对应下标
    int get_index(const T &value);

    //打印链表
    void print();
private:
    ListNode<T> *head_;
    size_t size_;
};

template <class T>
CycSingleList<T>::~CycSingleList()
{
    ListNode<T> *p=head_;
    while(size_>0){
        p=head_;
        head_=head_->next;
        --size_;

        delete p;
        p= nullptr;
    }

    head_= nullptr;
}

template <class T>
void CycSingleList<T>::insert(const int &index, const T &value)
{
    if(index<0 || index>size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    ListNode<T> *node=new ListNode<T>(value);
    if(size_==0){
        head_=node;
        head_->next=head_;
    }else{
        if(index==0){
            //寻找最后一个节点
            ListNode<T> *p=head_;
            for(;p->next!=head_;p=p->next);

            node->next=head_;
            head_=node;
            p->next=head_;
        }else{
            //寻找插入位置的上一个节点
            int key=0;
            ListNode<T> *p=head_;
            while(key < index-1){
                p=p->next;
                ++key;
            }

            node->next=p->next;
            p->next=node;
        }
    }
    ++size_;
}

template <class T>
T CycSingleList<T>::erase(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    ListNode<T> *node= nullptr;
    if(index == 0){
        ListNode<T> *p=head_;
        for(;p->next!=head_;p=p->next);

        node=head_;
        head_=node->next;
        p->next=head_;
    }else{
        int key=0;
        ListNode<T> *p=head_;
        while(key<index-1){
            p=p->next;
            ++key;
        }

        node=p->next;
        p->next=p->next->next;
    }

    --size_;
    T value=node->value_;
    delete node;
    node= nullptr;
    return value;
}

template<class T>
void CycSingleList<T>::set(const int &index, const T &value)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    int key=0;
    ListNode<T> *p=head_;
    while(key<index){
        p=p->next;
        ++key;
    }

    p->value_=value;
}

template <class T>
T& CycSingleList<T>::get(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    int key=0;
    ListNode<T> *p=head_;
    while(key<index){
        p=p->next;
        ++key;
    }

    return p->value_;
}

template <class T>
int CycSingleList<T>::get_index(const T &value)
{
    for(int i=0;i<size_;++i){
        if(get(i)==value){
            return i;
        }
    }

    return -1;
}

template <class T>
void CycSingleList<T>::print()
{
    for(int i=0;i<size_;++i){
        cout<<get(i)<<" ";
    }
    cout<<endl;
}

/*******************************************
*                 双向链表                   *
/*******************************************/
template <class T>
class DulList
{
public:
    DulList():head_(nullptr),size_(0){}
    ~DulList();

    //获取链表大小
    size_t size(){return size_;}
    //判断链表是否为空
    bool empty(){ return size_==0;}
    //获取头节点
    ListNode<T> *get_head(){return head_;}
    //获取任意位置节点
    ListNode<T> *get_node(const int &index);
    //根据节点获取该节点的下标
    int get_index(const T &value);

    //双向链表插入元素
    void push_back(const T &value);//在尾部插入元素
    void push_front(const T &value);//在头部插入元素
    void dul_insert(const int &index,const T &value);//在任意位置插入元素

    //双向链表删除元素
    T pop_front();//删除首元素
    T pop_back();//删除尾元素
    T dul_erase(const int &index);//删除任意位置元素

    //双向链表修改元素
    void dul_set(const int &index,const T &value);

    //双向链表查询元素
    T front();//获取首元素
    T back();//获取尾元素
    T dul_get(const int &index);//获取任意位置元素

    //打印链表
    void print();
private:
    ListNode<T> *head_;
    size_t size_;
};

template <class T>
DulList<T>::~DulList()
{
    if(head_!= nullptr){
        head_->front->next= nullptr;
        while(head_!= nullptr){
            ListNode<T> *temp=head_;
            head_=head_->next;
            delete temp;
            temp= nullptr;
        }
        size_=0;
    }
}

template <class T>
ListNode<T> *DulList<T>::get_node(const int &index)
{
    if(index < 0 || index >=size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    int i=0;
    ListNode<T> *cur=head_;
    while(i<index){
        cur=cur->next;
        ++i;
    }

    return cur;
}

template <class T>
int DulList<T>::get_index(const T &value)
{
    if(head_== nullptr){
        return -1;
    }

    int i=0;
    ListNode<T> *cur=head_;
    while(cur!=NULL){
        if(cur->value_==value){
            return i;
        }
        cur=cur->next;
        ++i;
    }

    return -1;
}

template <class T>
void DulList<T>::push_back(const T &value)
{
    ListNode<T> *node=new ListNode<T>(value);

    if(head_== nullptr){
        head_=node;
        head_->front=head_;
        head_->next=head_;
    }
    else{
        head_->front->next=node;
        node->front=head_->front;
        node->next=head_;
        head_->front=node;
    }
    ++size_;
}

template <class T>
void DulList<T>::push_front(const T &value)
{
    ListNode<T> *node=new ListNode<T>(value);

    if(head_== nullptr){
        head_=node;
        head_->front=head_;
        head_->next=head_;
    }else{
        node->next=head_;
        node->front=head_->front;
        head_->front->next=node;
        head_->front=node;
        head_=node;
    }
    ++size_;
}

template <class T>
void DulList<T>::dul_insert(const int &index,const T &value)
{
    if(index<0 || index > size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    if(index==0){
        push_front(value);
    } else if(index==size_){
        push_back(value);
    }else{
        ListNode<T> *cur=head_;
        int i=0;
        while(i<index){
            cur=cur->next;
            ++i;
        }

        ListNode<T> *node=new ListNode<T>(value);
        cur->front->next=node;
        node->front=cur->front;
        node->next=cur;
        cur->front=node;

        ++size_;
    }
}

template <class T>
T DulList<T>::pop_front()
{
    if(size_==0){
        return NULL;
    }else if(size_==1){
        T value=head_->value_;

        delete head_;
        head_= nullptr;
        --size_;

        return value;
    }else{
        T value=head_->value_;

        head_->front->next=head_->next;
        head_->next->front=head_->front;
        ListNode<T> *temp=head_;
        head_=head_->next;
        delete temp;
        temp= nullptr;
        --size_;
        return value;
    }
}

template <class T>
T DulList<T>::pop_back()
{
    if(size_==0){
        return NULL;
    } else if(size_==1){
        return pop_front();
    } else{
        T value=head_->front->value_;

        ListNode<T> *temp=head_->front;
        head_->front=temp->front;
        temp->front->next=head_;
        delete temp;
        temp= nullptr;
        --size_;

        return value;
    }
}

template <class T>
T DulList<T>::dul_erase(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    if(index==0){
        return pop_front();
    } else if(index==size_-1){
        return pop_back();
    } else{
        ListNode<T> *cur=head_;
        int i=0;
        while(i<index){
            cur=cur->next;
            ++i;
        }

        T value=cur->value_;
        cur->front->next=cur->next;
        cur->next->front=cur->front;
        delete cur;
        cur= nullptr;
        --size_;

        return value;
    }
}

template <class T>
void DulList<T>::dul_set(const int &index, const T &value)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    int i=0;
    ListNode<T> *cur=head_;
    while(i<index){
        cur=cur->next;
        ++i;
    }

    cur->value_=value;
}

template <class T>
T DulList<T>::front()
{
    if(head_== nullptr){
        return NULL;
    } else{
        return head_->value_;
    }

}

template <class T>
T DulList<T>::back()
{
    if(head_== nullptr){
        return NULL;
    }else{
        return head_->front->value_;
    }
}

template <class T>
T DulList<T>::dul_get(const int &index)
{
    if(index<0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    if(index==0){
        return front();
    }else if(index==size_-1){
        return back();
    }else{
        int i=0;
        ListNode<T> *cur=head_;
        while(i<index){
            cur=cur->next;
            ++i;
        }

        return cur->value_;
    }
}

template <class T>
void DulList<T>::print()
{
    if(head_== nullptr){
        return;
    } else{
        ListNode<T> *cur=head_;
        while(cur->next!=head_){
            cout<<cur->value_<<" ";
            cur=cur->next;
        }
        cout<<cur->value_<<endl;
    }
}

/*******************************************
*              双向循环链表                   *
/*******************************************/
template <class T>
class CycDulList{
public:
    CycDulList():head_(nullptr),size_(0){}
    ~CycDulList();

    //获取链表大小
    size_t size(){return size_;}
    //判断链表是否为空
    bool empty(){ return size_==0;}
    //获取头节点
    ListNode<T> *get_head(){return head_;}
    //获取任意位置节点
    ListNode<T> *get_node(const int &index);
    //根据节点获取该节点的下标
    int get_index(const T &value);

    //双向链表插入元素
    void push_back(const T &value);//在尾部插入元素
    void push_front(const T &value);//在头部插入元素
    void insert(const int &index,const T &value);//在任意位置插入元素

    //双向链表删除元素
    T pop_front();//删除首元素
    T pop_back();//删除尾元素
    T erase(const int &index);//删除任意位置元素

    //双向链表修改元素
    void set(const int &index,const T &value);

    //双向链表查询元素
    T front();//获取首元素
    T back();//获取尾元素
    T get(const int &index);//获取任意位置元素

    //打印链表
    void print();
private:
    ListNode<T> *head_;
    size_t size_;
};

template <class T>
CycDulList<T>::~CycDulList()
{
    if(head_!= nullptr){
        head_->front->next= nullptr;
        while(head_!= nullptr){
            ListNode<T> *temp=head_;
            head_=head_->next;
            delete temp;
            temp= nullptr;
        }
        size_=0;
    }
}

template <class T>
ListNode<T>* CycDulList<T>::get_node(const int &index)
{
    if(index < 0 || index >=size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    int i=0;
    ListNode<T> *cur=head_;
    while(i<index){
        cur=cur->next;
        ++i;
    }

    return cur;
}

template <class T>
int CycDulList<T>::get_index(const T &value)
{
    for(int i=0;i<size_;++i){
        if(get(i)==value){
            return i;
        }
    }

    return -1;
}

template <class T>
void CycDulList<T>::push_back(const T &value)
{
    ListNode<T> *node=new ListNode<T>(value);
    if(size_==0){
        push_front(value);
    }else{
        node->front=head_->front;
        node->next=head_;
        head_->front->next=node;
        head_->front=node;
    }
    ++size_;
}

template <class T>
void CycDulList<T>::push_front(const T &value)
{
    ListNode<T> *node=new ListNode<T>(value);
    if(size_==0){
        head_=node;
        head_->next=head_;
        head_->front=head_;
    }else{
        node->next=head_;
        node->front=head_->front;
        head_->front->next=node;
        head_->front=node;
        head_=node;
    }
    ++size_;
}

template <class T>
void CycDulList<T>::insert(const int &index, const T &value)
{
    if(index < 0 || index >size_){
        cout<<"index out of range,index < 0 or index > size_"<<endl;
        exit(0);
    }

    if(index == 0){
        push_front(value);
    }else if(index==size_){
        push_back(value);
    }else{
        int key=0;
        ListNode<T> *p=head_;
        while(key<index){
            p=p->next;
            ++key;
        }

        ListNode<T> *node=new ListNode<T>(value);
        node->next=p;
        node->front=p->front;
        p->front->next=node;
        p->front=node;

        ++size_;
    }
}

template <class T>
T CycDulList<T>::pop_front()
{
    if(size_==0){
        return -1;
    }else if(size_==1){
        T value=head_->value_;

        delete head_;
        head_= nullptr;
        --size_;
        return value;
    }else{
        T value=head_->value_;

        ListNode<T> *p=head_;
        head_=head_->next;

        head_->front=p->front;
        p->front->next=head_;

        delete p;
        p= nullptr;
        --size_;
        return value;
    }
}

template <class T>
T CycDulList<T>::pop_back()
{
    if(size_==0){
        return -1;
    }else if(size_==1){
        return pop_front();
    } else{
        T value=head_->front->value_;
        ListNode<T> *p=head_->front;

        head_->front=p->front;
        p->front->next=head_;

        delete p;
        p= nullptr;
        --size_;
        return value;
    }
}

template <class T>
T CycDulList<T>::erase(const int &index)
{
    if(index < 0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    if(index==0){
        return pop_front();
    }else if (index==size_-1){
        return pop_back();
    }else{
        int key=0;
        ListNode<T> *p=head_;
        while(key < index){
            p=p->next;
            ++key;
        }

        p->front->next=p->next;
        p->next->front=p->front;
        T value=p->value_;
        delete p;
        p= nullptr;
        --size_;

        return value;
    }
}

template <class T>
void CycDulList<T>::set(const int &index, const T &value)
{
    if(index < 0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }
    int key=0;
    ListNode<T> *p=head_;
    while(key < index){
        p=p->next;
        ++key;
    }
    p->value_=value;
}

template <class T>
T CycDulList<T>::front()
{
    if(head_== nullptr){
        return NULL;
    }else{
        return head_->value_;
    }
}

template <class T>
T CycDulList<T>::back()
{
    if(head_== nullptr){
        return NULL;
    }else{
        return head_->front->value_;
    }
}

template <class T>
T CycDulList<T>::get(const int &index)
{
    if(index < 0 || index >= size_){
        cout<<"index out of range,index < 0 or index >= size_"<<endl;
        exit(0);
    }

    if(index==0){
        return front();
    } else if(index ==size_-1){
        return back();
    }else{
        int key=0;
        ListNode<T> *p=head_;
        while(key < index){
            p=p->next;
            ++key;
        }

        return p->value_;
    }
}

template <class T>
void CycDulList<T>::print()
{
    for(int i=0;i<size_;++i){
        cout<<get(i)<<" ";
    }
    cout<<endl;
}

/*******************************************
*                 静态链表                   *
/*******************************************/

//定义静态节点
template <class T>
class StaticListNode
{
public:
    T value_;
    int next;       //指向下一个节点的游标
};

template <class T>
class StaticList
{
public:
    StaticList(const size_t &capacity = 10);
    ~StaticList();
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
    T &get(const int &index);
    //获取链表值对应下标
    int get_index(const T &value);

    //打印链表
    void print();
    void print_link();
private:
    StaticListNode<T> *head_;   //链表的头节点
    int data_head_;             //数据节点的头节点
    size_t size_;               //链表的大小
    size_t capacity_;           //链表的容量
};

template <class T>
StaticList<T>::StaticList(const size_t &capacity)
        :head_(nullptr),size_(0),capacity_(capacity)
{
    //创建备用链表并初始化
    head_=new StaticListNode<T>[capacity_];
    for(int i=0;i<capacity_-1;++i){
        head_[i].next=i+1;
    }
    head_[capacity_-1].next = 0;//链表最后节点的下一个节点位置为0

    data_head_=head_[0].next;
    if(head_[0].next){
        head_[0].next=head_[data_head_].next;
    }
}

template <class T>
StaticList<T>::~StaticList()
{
    delete[] head_;
    head_= nullptr;
    size_=0;
}

template <class T>
void StaticList<T>::insert(const int &index, const T &value)
{
    if(index < 1 || index > size_+1 || size_+1 >= capacity_){
        cout<<"index out of range,index < 1 or index >= size_+1 or size_+1 >= capacity_"<<endl;
        exit(0);
    }

    if(size_==0){
        head_[data_head_].value_=value;
        head_[data_head_].next=0;
    }else{
        //从备用链表中取出一个节点
        int insert=head_[0].next;
        if(head_[0].next){
            head_[0].next=head_[insert].next;
        }
        head_[insert].value_=value;

        if(index==1){
            //插入节点
            head_[insert].next=data_head_;
            data_head_=insert;
        }else{
            //搜索待插入位置的前面一个位置
            int temp_head=data_head_;
            int key=1;
            while(key<index-1){
                temp_head=head_[temp_head].next;
                ++key;
            }

            //插入节点
            head_[insert].next=head_[temp_head].next;
            head_[temp_head].next=insert;
        }
    }
    ++size_;
}

template <class T>
T StaticList<T>::erase(const int &index)
{
    if(index < 1 || index > size_+1 ){
        cout<<"index out of range,index < 1 or index > size_+1"<<endl;
        exit(0);
    }

    //搜索待删除位置的前面一个位置
    int temp_head=data_head_;
    int key=1;
    while(key<index-1){
        temp_head=head_[temp_head].next;
        ++key;
    }

    int cur=head_[temp_head].next;
    T value=head_[cur].value_;

    //从数据链表中删除节点
    head_[temp_head].next=head_[cur].next;
    //向备用链表中添加节点
    head_[cur].next=head_[0].next;
    head_[0].next=cur;
    --size_;

    return value;
}

template <class T>
void StaticList<T>::set(const int &index, const T &value)
{
    if(index < 1 || index > size_+1 ){
        cout<<"index out of range,index < 1 or index > size_+1"<<endl;
        exit(0);
    }

    //搜索位置的前面一个位置
    int temp_head=data_head_;
    int key=1;
    while(key< index){
        temp_head=head_[temp_head].next;
        ++key;
    }

    head_[temp_head].value_=value;
}

template <class T>
T& StaticList<T>::get(const int &index)
{
    if(index < 1 || index > size_+1 ){
        cout<<"index out of range,index < 1 or index > size_+1"<<endl;
        exit(0);
    }

    //搜索位置的前面一个位置
    int temp_head=data_head_;
    int key=1;
    while(key< index){
        temp_head=head_[temp_head].next;
        ++key;
    }

    return head_[temp_head].value_;
}

template <class T>
int StaticList<T>::get_index(const T &value)
{
    int temp_head=data_head_;
    while(head_[temp_head].next!=0){
        if(head_[temp_head].value_==value){
            return temp_head;
        }

        temp_head=head_[temp_head].next;
    }

    return -1;
}

template <class T>
void StaticList<T>::print()
{
    int temp_head=data_head_;
    while(head_[temp_head].next!=0){
        cout<<head_[temp_head].value_<<"->"<<head_[temp_head].next<<endl;
        temp_head=head_[temp_head].next;
    }
    cout<<head_[temp_head].value_<<"->"<<head_[temp_head].next<<endl;
}

template <class T>
void StaticList<T>::print_link()
{
    for(int i=0;i<capacity_;++i){
        cout<<head_[i].value_<<"->"<<head_[i].next<<endl;
    }
}

#endif //TESK_LIST_H
