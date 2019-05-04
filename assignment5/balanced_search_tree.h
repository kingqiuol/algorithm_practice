//
// Created by jinqiu on 2019/4/28.
//

#ifndef TESK_BALANCED_SEARCH_TREE_H
#define TESK_BALANCED_SEARCH_TREE_H

#include "utils.h"

/*******************************************
*              平衡二叉搜索树的实现            *
/*******************************************/
template <class K,class E>
class BalancedBSTree:public Dictionary<K,E>
{

};

/*******************************************
*             AVL平衡二叉搜索树的实现          *
/*******************************************/
template <class K,class E>
class AVLSearchTree:public BalancedBSTree<K,E>
{
public:
    AVLSearchTree():phead_(nullptr),size_(0){}
    ~AVLSearchTree();

    //判断字典是否为空
    bool empty() const{return size_==0;}
    //返回字典的大小
    int size() const{return size_;}
    //返回树的高度
    int get_height(BTreeNode<pair<const K,E>> *node){return node->height_;}
    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);
private:
    BTreeNode<pair<const K,E>> *leftLeftRotation_(BTreeNode<pair<const K,E>> *);    //左左单旋转
    BTreeNode<pair<const K,E>> *rightRightRotation_(BTreeNode<pair<const K,E>> *);  //右右单旋转
    BTreeNode<pair<const K,E>> *leftRightRotation_(BTreeNode<pair<const K,E>> *);   //左右旋转
    BTreeNode<pair<const K,E>> *rightLeftRotation_(BTreeNode<pair<const K,E>> *);   //右左旋转

    BTreeNode<pair<const K,E>> *insert_(BTreeNode<pair<const K,E>> *,
                                        const pair<const K,E>&);                    //插入字典
    BTreeNode<pair<const K,E>> *erase_(BTreeNode<pair<const K,E>> *,const K&);      //删除字典
    inline int max(int a,int b){return a>b?a:b;}                                    //比较两个数的大小
private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t size_;
};

template<class K,class E>
pair<const K, E>* AVLSearchTree<K,E>::find(const K &theKey)
{
    if(phead_== nullptr){
        return nullptr;
    }

    BTreeNode<pair<const K,E>> *p=phead_,*pp= nullptr;
    while(p!= nullptr){
        pp=p;
        if(theKey<p->element_.first){
            p=p->left_;
        }else if(theKey>p->element_.first){
            p=p->right_;
        }else{
            return &p->element_;
        }
    }

    return nullptr;
}

template<class K,class E>
BTreeNode<pair<const K,E>> *AVLSearchTree<K,E>::leftLeftRotation_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return nullptr;
    }

    BTreeNode<pair<const K,E>> *k=p->left_;
    p->left_=k->right_;
    k->right_=p;

    p->height_=max(get_height(k->left_),get_height(k->right_))+1;
    k->height_=max(get_height(k->right_),p->height_)+1;

    return k;
}

template <class K,class E>
BTreeNode<pair<const K,E>> *AVLSearchTree<K,E>::rightRightRotation_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return nullptr;
    }

    BTreeNode<pair<const K,E>> *k=p->right_;
    p->right_=k->left_;
    k->left_=p;

    p->height_=max(get_height(p->left_),get_height(p->right_))+1;
    k->height_=max(get_height(p),get_height(k->right_))+1;

    return k;
}

template<class K,class E>
BTreeNode<pair<const K,E>> *AVLSearchTree<K,E>::leftRightRotation_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return nullptr;
    }

    p->left_=rightRightRotation_(p->left_);

    return leftLeftRotation_(p);
}

template <class K,class E>
BTreeNode<pair<const K,E>>* AVLSearchTree<K,E>::rightLeftRotation_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return nullptr;
    }

    p->right_=leftLeftRotation_(p->right_);

    return rightRightRotation_(p);
}

template <class K,class E>
BTreeNode<pair<const K, E>> *AVLSearchTree<K,E>::insert_(BTreeNode<pair<const K, E>> *p,
                                                         const pair<const K, E> &theValue)
{
    if(p== nullptr){
        p=new BTreeNode<pair<const K,E>>(theValue);
        if(p == nullptr){
            cout << "ERROR: create avltree node failed!" << endl;
            return nullptr;
        }
        ++size_;
    }else if(theValue.first<p->element_.first){
        p->left_=insert_(p->left_,theValue);
        //插入节点后AVL树失去平衡，需要重新调整平衡
        if(get_height(p->left_)-get_height(p->right_)==2){
           if(theValue.first<p->left_->element_.first){
               p=leftLeftRotation_(p);
           } else{
               p=leftRightRotation_(p);
           }
        }
    }else if(theValue.first>p->element_.first){
        insert_(p->right_,theValue);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节
        if(get_height(p->right_)-get_height(p->left_)==2){
            if(theValue.first<p->right_->element_.first){
                p=rightLeftRotation_(p);
            }else{
                p=rightRightRotation_(p);
            }
        }
    }else{
        p->element_.second=theValue.second;
    }

    p->height_=max(get_height(p->left_),get_height(p->right_))+1;
    return p;
}

template <class K,class E>
void AVLSearchTree<K,E>::insert(const pair<const K, E> &theValue)
{
    insert_(phead_,theValue);
}

template <class K,class E>
BTreeNode<pair<const K,E>> * AVLSearchTree<K,E>::erase_(BTreeNode<pair<const K, E>> *p, const K &theKey)
{
    if(p== nullptr){
        return nullptr;
    }

    if()
}

template <class K,class E>
void AVLSearchTree<K,E>::erase(const K &theKey)
{
    if(phead_== nullptr || theKey== nullptr){
        return ;
    }

    if(find(theKey)){
        erase_(phead_,theKey);
    }
}

#endif //TESK_BALANCED_SEARCH_TREE_H
