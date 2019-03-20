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
        if(find(i)==value){
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


#endif //TESK_LIST_H
