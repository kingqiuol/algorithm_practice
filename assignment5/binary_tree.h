//
// Created by jinqiu on 19-3-10.
//

#ifndef TESK_BINARY_TREE_H
#define TESK_BINARY_TREE_H

#include <iostream>
#include <memory>

#include "list.h"
#include "queue.h"


using namespace std;

template <class T>
class BTree
{
public:
    virtual ~BTree(){}
    virtual bool empty() const =0;
    virtual size_t size() const=0;
    //前序遍历
    virtual void preOrder()=0;
    //中序遍历
    virtual void inOrder()=0;
    //后序遍历
    virtual void postOrder()=0;
    //层次遍历
    virtual void levelOrder()=0;
};

/*******************************************
*                二叉树的数组实现              *
/*******************************************/
template <class T>
class ArrayBTree
{
public:
    ArrayBTree(const size_t &capacity=10);
    ~ArrayBTree(){}

    //二叉树元素的数量
    size_t size() const{return size_;}
    //二叉树的容量
    size_t max_size() const{return capacity_;}
    //二叉树是否为空
    bool empty() const{return size_==0;};


    //向二叉树中插入元素
    void insert(const T &value);

    //删除二叉树中的元素
    void erase(const T &value);

    //修改二叉树中的元素
    void set(const T &index,const T &value);
    //查找二叉树中的元素
    T get(const int &index);

    //二叉树中搜索对应值位置的下标
    int find(const T &value);

    //打印二叉树
    void print();

    //找index节点的前驱
    void predecessor(const int &index,T &value,int &sindex);
    //找index节点的后继
    void successor(const int &index,T &value,int &sindex);

    //前序遍历
    void preOrder();
    //中序遍历
    void inOrder();
    //后序遍历
    void postOrder();
    //层次遍历
    void levelOrder();
private:
    void insert_(const T &value,int index);     //插入元素
    void erase_(const int &index);              //删除元素并重新调整二叉树
    int find_(const T &value,int index);        //搜索二叉树

    void preOrder_(const int &index);           //前序遍历
    void inOrder_(const int &index);            //中序遍历
    void postOrder_(const int &index);          //后序遍历
    void levelOrder_(const int &index);         //层次遍历
private:
    shared_ptr<T> ptr_;                         //存储二叉树数的数组
    size_t size_;                               //二叉树元素的大小
    size_t capacity_;                           //二叉树的容量
};

template <class T>
ArrayBTree<T>::ArrayBTree(const size_t &capacity):capacity_(capacity),
                                                  size_(0)
{
    ptr_=shared_ptr<T>(new T[capacity_],[](T *p){delete[] p;});
    fill(ptr_.get(),ptr_.get()+capacity_,-1);
}

template <class T>
void ArrayBTree<T>::insert_(const T &value, int index)
{
    if(index>=capacity_){
        cerr<<"index out of capacity(in function insert_)"<<endl;
        exit(0);
    }

    if(ptr_.get()[index]==-1){
        ptr_.get()[index]=value;
    } else{
        if(ptr_.get()[index]>=value){
            insert_(value,index*2+1);
        }else{
            insert_(value,index*2+2);
        }
    }
}

template <class T>
void ArrayBTree<T>::insert(const T &value)
{
    if(size_+1>=capacity_){
        cerr<<"tree capacity is out of max size"<<endl;
        exit(0);
    }

    if(this->empty()){
        *ptr_.get()=value;
    }else{
        insert_(value,0);
    }

    ++size_;
}

template <class T>
void ArrayBTree<T>::erase_(const int &index)
{
    if(index*2+1>=capacity_ || (ptr_.get()[index*2+1]==-1 &&
                               ptr_.get()[index*2+2]==-1)){
        ptr_.get()[index]=-1;
        return ;
    }
    if(ptr_.get()[index*2+1]!=-1 && (ptr_.get()[index*2+2]==-1 ||
            ptr_.get()[index*2+2]>=capacity_)){
        ptr_.get()[index]=-1;
        T value=ptr_.get()[index*2+1];
        ptr_.get()[index*2+1]=-1;
        insert(value);
        return ;
    }

    ptr_.get()[index]=ptr_.get()[index*2+2];
    erase_(index*2+2);
}

template <class T>
void ArrayBTree<T>::erase(const T &value)
{
    int index=find(value);

    if(-1==index){
        cerr<<"erase id fail,"<<value<<" don't in the tree"<<endl;
        exit(0);
    }else{
        erase_(index);
        --size_;
    }
}

template <class T>
void ArrayBTree<T>::set(const T &index, const T &value)
{
    if(index<0 || index>=capacity_){
        cerr<<"index out of capacity(in function insert_)"<<endl;
        exit(0);
    }

    if(ptr_.get()[index]==-1){
        insert(value);
    }else{
        erase(ptr_.get()[index]);
        insert(value);
    }
}

template <class T>
T ArrayBTree<T>::get(const int &index)
{
    if(index<0 || index>=capacity_){
        cerr<<"index out of capacity(in function insert_)"<<endl;
        exit(0);
    }

    if(ptr_.get()[index]==-1){
        cerr<<"Don't find value in the tree"<<endl;
        return -1;
    } else{
        return ptr_.get()[index];
    }

}

template <class T>
int ArrayBTree<T>::find_(const T &value, int index)
{
    if(ptr_.get()[index]==-1 || index>=capacity_){
        cerr<<"Don't find "<<value<<" in the tree"<<endl;
        return -1;
    }

    if(ptr_.get()[index]==value){
        return index;
    }else if(ptr_.get()[index] > value){
        return find_(value,index*2+1);
    } else{
        return find_(value,index*2+2);
    }
}

template <class T>
int ArrayBTree<T>::find(const T &value)
{
    if(this->empty()){
        cerr<<"tree is empty"<<endl;
        exit(0);
    }

    return find_(value,0);
}

template <class T>
void ArrayBTree<T>::print()
{
    for(auto i=0;i<capacity_;++i){
        cout<<ptr_.get()[i]<<" ";
    }
    cout<<endl;
}

/**
 *找结点(x)的前驱结点。即查找"二叉树中数据值小于该结点"的"最大结点"
 * 分三种情况
 * 1. 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
 * 2. x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
 * 3. x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
 **/
template <class T>
void ArrayBTree<T>::predecessor(const int &index, T &value, int &sindex)
{
    //情况1
    if(ptr_.get()[index*2+1]!=-1){
        int left=index*2+1;

        while(left<capacity_ && ptr_.get()[left]!=-1){
            left=left*2+2;

        }

        sindex= (left-2)/2;
        value=ptr_.get()[sindex];
    }else{
        //情况2、3
        if(index%2==0){//index为右孩子
            sindex=(index-2)/2;
            value=ptr_.get()[sindex];
        } else{//index为左孩子
            int parent=(index-1)/2;
            while(parent>=0 && ptr_.get()[parent*2+2]==-1){
                if(parent%2==0) parent=(parent-2)/2;
                else parent=(parent-1)/2;
            }
            sindex=parent;
            value=ptr_.get()[sindex];
        }
    }
}

/*
 *找节点（x）的后继节点。即查找二叉树中数值大于该节点的最小值
 *分三种情况
 * 1. x有右孩子，找到以右孩子为根的子树的最小节点
 * 2. x没有右孩子，当x为左孩子，则x的父节点为后继节点
 * 3. x没有右孩子，当x为右孩子，则找x的最低父节点，并且该父节点具有左孩子
 **/
template <class T>
void ArrayBTree<T>::successor(const int &index, T &value, int &sindex)
{
    //情况1
    if(ptr_.get()[index*2+2]!=-1){
        int left=index*2+2;
        while(left<capacity_ && ptr_.get()[left]!=-1){
            left=left*2+1;
        }
        sindex=(left-1)/2;
        value=ptr_.get()[sindex];
    }else{
        //情况2、3
        if(index%2==1){//index为左孩子
            sindex=(index-1)/2;
            value=ptr_.get()[sindex];
        } else{//index为右孩子
            int parent=(index-2)/2;
            while(parent>=0 && ptr_.get()[parent*2+1]==-1){
                if(parent%2==0) parent=(parent-2)/2;
                else parent=(parent-1)/2;
            }
            sindex=parent;
            value=ptr_.get()[sindex];
        }
    }
}

template <class T>
void ArrayBTree<T>::preOrder_(const int &index)
{
    if(index>=capacity_ || ptr_.get()[index]==-1){
        return;
    }

    cout<<ptr_.get()[index]<<" ";
    preOrder_(index*2+1);
    preOrder_(index*2+2);
}

template <class T>
void ArrayBTree<T>::preOrder()
{
    preOrder_(0);
}

template <class T>
void ArrayBTree<T>::inOrder_(const int &index)
{
    if(index>=capacity_ || ptr_.get()[index]==-1){
        return;
    }

    inOrder_(index*2+1);
    cout<<ptr_.get()[index]<<" ";
    inOrder_(index*2+2);
}

template <class T>
void ArrayBTree<T>::inOrder()
{
    inOrder_(0);
}

template <class T>
void ArrayBTree<T>::postOrder_(const int &index)
{
    if(index>=capacity_ || ptr_.get()[index]==-1){
        return;
    }



    postOrder_(index*2+1);
    postOrder_(index*2+2);
    cout<<ptr_.get()[index]<<" ";
}

template <class T>
void ArrayBTree<T>::postOrder()
{
    postOrder_(0);
}

template <class T>
void ArrayBTree<T>::levelOrder_(const int &index)
{
    if(index>=capacity_ || ptr_.get()[index]==-1){
        return;
    }

    int left=0,right=0;
    left=right=index;
    while(left<capacity_ && right<capacity_){
        for(int i=left;i<=right;++i){
            T value=ptr_.get()[i];
            if(value!=-1){
                cout<<value<<" ";
            }
        }
        cout<<endl;
        left=left*2+1;
        right=right*2+2;
    }

}

template <class T>
void ArrayBTree<T>::levelOrder()
{
    levelOrder_(0);
}
/*******************************************
*                二叉树的链表实现              *
/*******************************************/
template <class T>
class ListBTree:public BTree<T>
{
public:
    ListBTree():phead_(nullptr),size_(0){}
    ListBTree(const ListBTree<T> &other); //拷贝构造函数，复制整棵树
    ~ListBTree();

    //获取二叉树的根
    ListNode<T> *get_root(){return phead_;}
    //判断二叉树是否为空
    bool empty() const{return size_==0;}
    //返回二叉树元素的个数
    size_t size() const{return size_;}

    //插入节点
    void insert(const T &value);
    void insert(const ListNode<T> &theNode);

    //删除节点
    void erase(const T &value);

    //二叉树中搜索对应值位置
    ListNode<T> *find(const T &value);

    //拷贝二叉树
    ListNode<T> *clone() const;

    //找节点的前驱
    ListNode<T> *predecessor(const T &value);
    //找节点的后继
    ListNode<T> *successor(const T &value);

    //前序遍历
    void preOrder();
    //中序遍历
    void inOrder();
    //后序遍历
    void postOrder();
    //层次遍历
    void levelOrder();
private:
    void insert_(ListNode<T> *node,ListNode<T> *&cur);  //插入节点
    void erase_(const T &value,ListNode<T> *&node);     //删除节点
    void delete_(ListNode<T> *node);                    //删除整个二叉树
    ListNode<T> *clone_(ListNode<T> *node) const;       //拷贝二叉树

    void preOrder_(ListNode<T> *node);                  //前序遍历
    void inOrder_(ListNode<T> *node);                   //中序遍历
    void postOrder_(ListNode<T> *node);                 //后序遍历

    ListNode<T> *get_parents(ListNode<T> *node);        //获取当前节点的父节点
private:
    ListNode<T> *phead_;
    size_t size_;
};

template <class T>
ListBTree<T>::ListBTree(const ListBTree<T> &other)
{
    if(other.empty()){
        phead_= nullptr;
    }else{
        phead_=other.clone();
    }
}

template <class T>
void ListBTree<T>::delete_(ListNode<T> *node)
{
    if(node!= nullptr){
        ListNode<T> *cur=node;
        delete_(node->front);
        delete_(node->next);
        delete cur;
        cur= nullptr;
    }
}

template <class T>
ListBTree<T>::~ListBTree()
{
    if(phead_!= nullptr){
        delete_(phead_);
    }
}

template <class T>
void ListBTree<T>::insert_(ListNode<T> *node,ListNode<T> *&cur)
{
    if(cur== nullptr) {
        cur = new ListNode<T>(node->value_);
        return ;
    }

    if(cur->value_<=node->value_){
        insert_(node,cur->next);
    } else{
        insert_(node,cur->front);
    }
}

template <class T>
void ListBTree<T>::insert(const T &value)
{
    ListNode<T> *node=new ListNode<T>(value);

    if(phead_== nullptr){
        phead_=node;
    }else{
        insert_(node,phead_);
    }

    ++size_;
}

template <class T>
void ListBTree<T>::insert(const ListNode<T> &theNode)
{
    ListNode<T> *node=new ListNode<T>(theNode);

    if(phead_== nullptr){
        phead_=node;
    }else{
        insert_(node,phead_);
    }

    ++size_;
}

template <class T>
void ListBTree<T>::erase_(const T &value, ListNode<T> *&node)
{
    if(node== nullptr){
        return ;
    }

    if(value<node->value_){
        erase_(value,node->front);
    } else if(value>node->value_){
        erase_(value,node->next);
    }else if(node->front!= nullptr && node->next!= nullptr){
        ListNode<T> *tmp=node->next;
        while(tmp->front!= nullptr){
            tmp=tmp->front;
        }

        node->value_=tmp->value_;
        erase_(node->value_,node->next);
    }else{
        ListNode<T> *tmp=node;
        node=(node->front!= nullptr)?node->front:node->next;
        delete tmp;
        tmp= nullptr;
    }
}

template <class T>
void ListBTree<T>::erase(const T &value)
{
    if(phead_== nullptr){
        return ;
    }

    erase_(value,phead_);
    --size_;
}

template <class T>
ListNode<T> *ListBTree<T>::find(const T &value)
{
    if(phead_== nullptr){
        return nullptr;
    }

    ListNode<T> *cur=phead_;
    while(cur != nullptr){
        if(cur->value_<value){
            cur=cur->next;
        } else if(cur->value_>value){
            cur=cur->front;
        }else{
            return cur;
        }
    }
    return nullptr;
}

template <class T>
ListNode<T> *ListBTree<T>::clone_(ListNode<T> *node) const
{
    if(node== nullptr){
        return nullptr;
    }

    return new ListNode<T>(node->value_,
                           clone_(node->front),
                           clone_(node->next));
}

template <class T>
ListNode<T> *ListBTree<T>::clone() const
{
    if(phead_== nullptr){
        return nullptr;
    }

    return clone_(phead_);
}

template <class T>
ListNode<T> *ListBTree<T>::get_parents(ListNode<T> *node)
{
    if(phead_== nullptr){
        return nullptr;
    }
    ListNode<T> *cur=phead_;
    ListNode<T> *pre=cur;
    while(cur!= nullptr){
        if(cur->value_<node->value_){
            pre=cur;
            cur=cur->next;
        } else if(cur->value_>node->value_){
            pre=cur;
            cur=cur->front;
        }else{
            return pre;
        }
    }
    return nullptr;
}

template <class T>
ListNode<T> *ListBTree<T>::predecessor(const T &value)
{
    ListNode<T> *node=find(value);

    if(node== nullptr){
        return node;
    }

    if(node->front != nullptr){
        ListNode<T> *cur=node->front;
        while(cur->next!= nullptr){
            cur=cur->next;
        }

        return cur;
    }else{
        ListNode<T> *pre=node;
        while(node!=phead_){
            pre=get_parents(pre);
            if(pre->next==node){
                return pre;
            }
        }
        return nullptr;
    }
}

template <class T>
ListNode<T> *ListBTree<T>::successor(const T &value)
{
    ListNode<T> *node=find(value);

    if(node== nullptr){
        return node;
    }

    if(node->next != nullptr){
        ListNode<T> *cur=node->next;
        while(cur->front!= nullptr){
            cur=cur->front;
        }
        return cur;
    }else{
        ListNode<T> *pre=node;

        while(pre!=phead_){
            pre=get_parents(pre);
            if(pre->front==node){
                return pre;
            }
        }
        return nullptr;
    }
}

template <class T>
void ListBTree<T>::preOrder_(ListNode<T> *node)
{
    if(node== nullptr){
        return ;
    }
    cout<<node->value_<<" ";
    preOrder_(node->front);

    preOrder_(node->next);
}

template <class T>
void ListBTree<T>::preOrder()
{
    if(phead_== nullptr){
        return ;
    }

    preOrder_(phead_);
}

template <class T>
void ListBTree<T>::inOrder_(ListNode<T> *node)
{
    if(node== nullptr){
        return ;
    }

    inOrder_(node->front);
    cout<<node->value_<<" ";
    inOrder_(node->next);
}

template <class T>
void ListBTree<T>::inOrder()
{
    if(phead_== nullptr){
        return ;
    }

    inOrder_(phead_);
}

template <class T>
void ListBTree<T>::postOrder_(ListNode<T> *node)
{
    if(node== nullptr){
        return ;
    }

    postOrder_(node->front);
    postOrder_(node->next);
    cout<<node->value_<<" ";
}

template <class T>
void ListBTree<T>::postOrder()
{
    if(phead_== nullptr){
        return ;
    }

    postOrder_(phead_);
}

template <class T>
void ListBTree<T>::levelOrder()
{
    if(phead_== nullptr){
        return ;
    }

    ListQueue<ListNode<T>* > queue;
    queue.push(phead_);
    while(!queue.empty()){
        ListNode<T> *cur=queue.pop();
        cout<<cur->value_<<" ";
        if(cur->front!= nullptr){
            queue.push(cur->front);
        }
        if(cur->next!= nullptr){
            queue.push(cur->next);
        }
    }
}

#endif //TESK_BINARY_TREE_H
