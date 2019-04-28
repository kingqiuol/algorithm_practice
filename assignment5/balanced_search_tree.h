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
    int get_height(){return height_;}
    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);
private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t size_;
    size_t height_;//树高
};

//template<class K,class E>
//pair<const K, E>* AVLSearchTree<K,E>::find(const K &theKey)
//{
//
//}

template <class K,class E>
void AVLSearchTree<K,E>::insert(const pair<const K, E> &theValue)
{
    if(phead_== nullptr){
        BTreeNode<pair<const K,E>> *node=new BTreeNode<pair<const K,E>>(theValue);
        phead_=node;
        height_=0;
    }
}

#endif //TESK_BALANCED_SEARCH_TREE_H
