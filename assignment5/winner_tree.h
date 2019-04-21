//
// Created by jinqiu on 19-4-15.
//

#ifndef TESK_WINNER_TREE_H
#define TESK_WINNER_TREE_H

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

using namespace std;

template<class T>
class WinnerTree
{
public:
    virtual ~WinnerTree(){}
    //使用数组thePlayer初始化竞赛树
    virtual void initialize(vector<T> &thePlayer)=0;
    //返回赢着的索引
    virtual int winner() const = 0;
    //在竞赛这改变后，重新进行竞赛
    virtual void rePlay(const int &thePlayer,const T &value)=0;
};

/*******************************************
*                 赢者树的实现               *
/*******************************************/
template <class T>
class CompeleteWinnerTree: public WinnerTree<T>
{
public:
    CompeleteWinnerTree(vector<T> &players);
    ~CompeleteWinnerTree(){}

    //使用数组thePlayer初始化竞赛树
    void initialize(vector<T> &thePlayer);

    //返回赢着的索引
    int winner() const{return *ptr_.get();}

    //在竞赛这改变后，重新进行竞赛
    void rePlay(const int &thePlayer,const T &value);

    //输出
    void print();
private:
    void play(int parent,int left,int right);
private:
    shared_ptr<T> ptr_;
    size_t tree_size_;
    size_t theNumberOfPlayers_;
};

template <class T>
CompeleteWinnerTree<T>::CompeleteWinnerTree(vector<T> &players)
{
    theNumberOfPlayers_=players.size();             //竞赛者的个数
    size_t internal_node=theNumberOfPlayers_-1;     //内部节点的个数
    tree_size_=internal_node+theNumberOfPlayers_;   //总的节点个数

    //创建竞赛树
    ptr_=shared_ptr<T>(new T[tree_size_],[](T *p){delete[] p;});

    //初始化竞赛树
    initialize(players);
}

template <class T>
void CompeleteWinnerTree<T>::play(int parent, int left, int right)
{
    //进行比赛
    ptr_.get()[parent]=ptr_.get()[left]>ptr_.get()[right]?
                       ptr_.get()[left]:ptr_.get()[right];

    //如果父节点为当前树的右节点
    while(parent%2==0 && parent > 0){
        ptr_.get()[parent/2-1]=ptr_.get()[parent-1]>ptr_.get()[parent]?
                               ptr_.get()[parent-1]:ptr_.get()[parent];

        parent=parent/2-1;
    }
}

template <class T>
void CompeleteWinnerTree<T>::initialize(vector<T> &thePlayer)
{
    //最底层最左端内部节点的编号：2^(log2(n-1))-1
    int bottom_inner_node = pow(2,floor(log2(theNumberOfPlayers_-1)))-1;
    //最左侧第一个竞赛者的下标的偏移量
    int offset=2*bottom_inner_node+1;
    //最底层外部节点的个数：
    int lowExt=2*(theNumberOfPlayers_-bottom_inner_node-1);

    //初始化竞赛树
    for(int i=0;i<theNumberOfPlayers_;++i){
        if(i<lowExt){
            ptr_.get()[offset+i]=thePlayer[i];
        } else{
            ptr_.get()[i-lowExt+theNumberOfPlayers_-1]=thePlayer[i];
        }
    }

    //进行比赛
    int i;
    //对最底层最外层竞赛者进行比赛
    for(i=1;i<lowExt;i+=2){
        play((i+offset)/2-1,i+offset-1,i+offset);
    }

    //处理剩余的外部节点
    //如果外部节点为奇数
    if(theNumberOfPlayers_%2==1){
        play(theNumberOfPlayers_/2-1,theNumberOfPlayers_-2,theNumberOfPlayers_-1);
        i=lowExt+2;
    }else{
        i=lowExt+1;
    }
    for(;i<theNumberOfPlayers_;i+=2){
        play((i-lowExt+theNumberOfPlayers_-1)/2-1,
             i-lowExt+theNumberOfPlayers_-2,
             i-lowExt+theNumberOfPlayers_-1);
    }
}

template <class T>
void CompeleteWinnerTree<T>::rePlay(const int &thePlayer,const T &value) {
    if (thePlayer < 0 || thePlayer >= theNumberOfPlayers_) {
        cout << "player index is outof range" << endl;
        exit(0);
    }

    //最底层最左端内部节点的编号：2^(log2(n-1))-1
    int bottom_inner_node = pow(2, floor(log2(theNumberOfPlayers_ - 1))) - 1;
    //最左侧第一个竞赛者的下标的偏移量
    int offset = 2 * bottom_inner_node + 1;
    //最底层外部节点的个数：
    int lowExt = 2 * (theNumberOfPlayers_ - bottom_inner_node - 1);
    int parents, left, right;//定义父节点和左右孩子节点

    //找出第一个需要重赛的节点以及他的左右孩纸
    //当前节点在竞赛树中的位置
    int tmp;
    if (thePlayer < lowExt) {
        tmp=offset+thePlayer;
    }else{
        tmp=(thePlayer-lowExt+theNumberOfPlayers_-1);
    }
    //重新给外节点赋值
    ptr_.get()[tmp]=value;
    //当前节点的位置父节点
    parents=tmp%2==0?tmp/2-1:tmp/2;
    //左右节点
    left=2*parents+1;
    right=left+1;
    ptr_.get()[parents]=(ptr_.get()[left]<ptr_.get()[right])?
                        ptr_.get()[right]:ptr_.get()[left];

    //第二个需要重赛的节点中的特殊情况，即包含内部和外部节点
    if(theNumberOfPlayers_%2==1 && parents==theNumberOfPlayers_-2){
        parents=parents/2;
        left=theNumberOfPlayers_-2;
        right=left-1;
        ptr_.get()[parents]=(ptr_.get()[left]<ptr_.get()[right])?
                            ptr_.get()[right]:ptr_.get()[left];
    }
    //处理剩余的节点
    parents=parents%2==0?parents/2-1:parents/2;
    for(;parents>=0;parents=parents%2==0?parents/2-1:parents/2){
        //左右节点
        left=2*parents+1;
        right=left+1;
        ptr_.get()[parents]=(ptr_.get()[left]<ptr_.get()[right])?
                            ptr_.get()[right]:ptr_.get()[left];
    }
}

template<class T>
void CompeleteWinnerTree<T>::print()
{
    //最底层最左端内部节点的编号：2^(log2(n-1))-1
    int bottom_inner_node = pow(2, floor(log2(theNumberOfPlayers_ - 1))) - 1;
    //最左侧第一个竞赛者的下标的偏移量
    int offset = 2 * bottom_inner_node + 1;
    //最底层外部节点的个数：
    int lowExt = 2 * (theNumberOfPlayers_ - bottom_inner_node - 1);

    cout << "number of players  = " << theNumberOfPlayers_
         << " lowExt = " << lowExt
         << " offset = " << offset
         << " tree_size= "<<tree_size_<<endl;
    cout << "complete winner tree pointers are" << endl;
    for (int i = 0; i < tree_size_; i++)
        cout << ptr_.get()[i] << ' ';
    cout << endl;
}

/*******************************************
*                 输者树的实现               *
/*******************************************/


#endif //TESK_WINNER_TREE_H
