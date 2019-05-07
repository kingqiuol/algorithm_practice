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
public:
    //关键字按升序输出
    virtual void ascend()=0;
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
    int get_height(BTreeNode<pair<const K,E>> *node)
    { if(node== nullptr) return 0; else return node->height_;}

    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend();
private:
    void delete_(BTreeNode<pair<const K,E>> *p);                                    //AVL平衡树的销毁

    BTreeNode<pair<const K,E>> *leftLeftRotation_(BTreeNode<pair<const K,E>> *);    //左左单旋转
    BTreeNode<pair<const K,E>> *rightRightRotation_(BTreeNode<pair<const K,E>> *);  //右右单旋转
    BTreeNode<pair<const K,E>> *leftRightRotation_(BTreeNode<pair<const K,E>> *);   //左右旋转
    BTreeNode<pair<const K,E>> *rightLeftRotation_(BTreeNode<pair<const K,E>> *);   //右左旋转

    BTreeNode<pair<const K,E>> *insert_(BTreeNode<pair<const K,E>> *&,
                                        const pair<const K,E>&);                    //插入字典
    BTreeNode<pair<const K,E>> *erase_(BTreeNode<pair<const K,E>> *&,const K&);      //删除字典
    void inOrder_(BTreeNode<pair<const K,E>> *p);                                   //中序遍历
    inline int max(int a,int b){return a>b?a:b;}                                    //比较两个数的大小
private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t size_;
};

template <class K,class E>
void AVLSearchTree<K,E>::delete_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return ;
    }

    delete_(p->left_);
    delete_(p->right_);

    delete p;
    p= nullptr;
}

template <class K,class E>
AVLSearchTree<K,E>::~AVLSearchTree()
{
    if(phead_!= nullptr){
        delete_(phead_);
    }
}

template<class K,class E>
pair<const K, E>* AVLSearchTree<K,E>::find(const K &theKey)
{
    if(phead_== nullptr){
        return nullptr;
    }

    BTreeNode<pair<const K,E>> *p=phead_;
    while(p!= nullptr){
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
BTreeNode<pair<const K, E>> *AVLSearchTree<K,E>::insert_(BTreeNode<pair<const K, E>> *&p,
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
    phead_=insert_(phead_,theValue);
}

template <class K,class E>
BTreeNode<pair<const K,E>> * AVLSearchTree<K,E>::erase_(BTreeNode<pair<const K, E>> *&p, const K &theKey)
{
    if(p== nullptr){
        return nullptr;
    }

    if(theKey<p->element_.first){
        p->left_=erase_(p->left_,theKey);

        // 删除节点后，若AVL树失去平衡，则进行相应的调节
        if(get_height(p->right_)-get_height(p->left_)==2){
            BTreeNode<pair<const K,E>> *r=p->right_;
            if(get_height(r->left_)>get_height(r->right_)){
                p=rightLeftRotation_(p);
            }else{
                p=rightRightRotation_(p);
            }
        }
    }else if(theKey>p->element_.first){
        p->right_=erase_(p->right_,theKey);

        // 删除节点后，若AVL树失去平衡，则进行相应的调节
        if(get_height(p->left_)-get_height(p->right_)==2){
            BTreeNode<pair<const K,E>> *l=p->left_;
            if(get_height(l->left_)<get_height(l->right_)){
                p=leftRightRotation_(p);
            }else{
                p=leftLeftRotation_(p);
            }
        }
    }else{
        BTreeNode<pair<const K,E>> *tmp=p;

        //如果左右孩子都不为空
        if(p->left_!=nullptr && p->right_!= nullptr){
            // 如果tree的左子树比右子树高；
            // 则(01)找出tree的左子树中的最大节点
            //   (02)将该最大节点的值赋值给tree。
            //   (03)删除该最大节点。
            // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
            // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
            if(get_height(p->left_)>get_height(p->right_)){
                //搜索左子树最大节点
                BTreeNode<pair<const K,E>> *cur=p->left_, *pre= p;
                while(cur!= nullptr){
                    pre=cur;
                    cur=cur->right_;
                }

                BTreeNode<pair<const K,E>> *newNode=new BTreeNode<pair<const K,E>>
                        (pre->element_,p->left_,p->right_);
                p=newNode;
                erase_(p->left_,pre->element_.first);
            }else{
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                BTreeNode<pair<const K,E>> *cur=p->right_,*pre=p;
                while(cur!=nullptr){
                    pre=cur;
                    cur=cur->left_;
                }

                BTreeNode<pair<const K,E>> *newNode=new BTreeNode<pair<const K,E>>
                        (pre->element_,p->left_,p->right_);
                p=newNode;
                erase_(p->right_,pre->element_.first);
            }
        }else{
            p=p->left_== nullptr?p->right_:p->left_;
        }

        delete tmp;
    }

    return p;
}

template <class K,class E>
void AVLSearchTree<K,E>::erase(const K &theKey)
{
    if(phead_== nullptr){
        return ;
    }

    if(find(theKey)){
        erase_(phead_,theKey);
        --size_;
    }
}

template <class K,class E>
void AVLSearchTree<K,E>::inOrder_(BTreeNode<pair<const K, E>> *p)
{
    if(p== nullptr){
        return ;
    }

    inOrder_(p->left_);
    cout<<p->element_.first<<"->"<<p->element_.second<<endl;
    inOrder_(p->right_);
}

template <class K,class E>
void AVLSearchTree<K,E>::ascend()
{
    if(phead_== nullptr){
        return;
    }

    inOrder_(phead_);
}

/*******************************************
*            红-黑平衡二叉搜索树的实现          *
/*******************************************/
template <class K,class E>
class RBSearchTree:public BalancedBSTree<K,E>
{
public:
    RBSearchTree():phead_(nullptr),size_(0){}
    ~RBSearchTree();

    //判断字典是否为空
    bool empty() const{return size_==0;}
    //返回字典的大小
    int size() const{return size_;}
    //返回树的高度
    int get_height(BTreeNode<pair<const K,E>> *node)
    { if(node== nullptr) return 0; else return node->height_;}

    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend();

private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t size_;
};

template <class K,class E>
pair<const K, E>* RBSearchTree<K,E>::find(const K &theKey)
{
    if(phead_== nullptr){
        return nullptr;
    }

    BTreeNode<pair<const K,E>> *p=phead_;
    while(p!= nullptr){
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

template <class K,class E>
void RBSearchTree<K,E>::insert(const pair<const K, E> &theValue)
{

}

#endif //TESK_BALANCED_SEARCH_TREE_H
