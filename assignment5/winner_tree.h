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
    virtual void rePlay(int thePlayer)=0;
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
    void rePlay(int thePlayer);
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
    while(parent/2==0 && parent > 0){
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
    for(i=1;i<lowExt;++i){
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
void CompeleteWinnerTree<T>::rePlay(int thePlayer)
{

}

/*******************************************
*                 输者树的实现               *
/*******************************************/


#endif //TESK_WINNER_TREE_H
