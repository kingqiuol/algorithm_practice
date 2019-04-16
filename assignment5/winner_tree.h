//
// Created by jinqiu on 19-4-15.
//

#ifndef TESK_WINNER_TREE_H
#define TESK_WINNER_TREE_H

#include <iostream>
#include <memory>
#include <math.h>

using namespace std;

template<class T>
class WinnerTree
{
public:
    virtual ~WinnerTree(){}
    //使用数组thePlayer初始化竞赛树
    virtual void initialize(T *thePlayer,int theNumberOfPlayers)=0;
    //返回赢着的索引
    virtual int winner() const = 0;
    //在竞赛这改变后，重新进行竞赛
    virtual void rePlay(int thePlayer)=0;
};

/*******************************************
*                 赢者树的实现               *
/*******************************************/
template <class T>
class CompeleteWinnerTree: public WinnerTree
{
public:
    CompeleteWinnerTree(vector<T> &players);
    ~CompeleteWinnerTree(){}

    //使用数组thePlayer初始化竞赛树
    void initialize(T *thePlayer,int theNumberOfPlayers);

    //返回赢着的索引
    int winner() const;

    //在竞赛这改变后，重新进行竞赛
    void rePlay(int thePlayer);

public:
    shared_ptr<T> ptr_;
    int tree_size_;
};

template <class T>
CompeleteWinnerTree::CompeleteWinnerTree(vector<T> &players)
{
    int internal_node=players.size()-1;//内部节点的个数
    tree_size_=internal_node+players.size();//总的节点个数
    //创建竞赛树
    ptr_=shared_ptr<T>(new T[tree_size_],[](T *p){delete[] p;});
    initialize(ptr_.get(),players.size());
}

template <class T>
void CompeleteWinnerTree::initialize(T *thePlayer, int theNumberOfPlayers)
{
    //最底层最左端内部节点的编号：2^(log2(n-1))-1
    int bottom_inner_node=pow(2,floor(log2(theNumberOfPlayers-1)))-1;
    //最左侧第一个竞赛者的下标的偏移量
    int offset=2*bottom_inner_node+1;
    //最底层外部节点的个数：
    int lowExt=2*(theNumberOfPlayers-bottom_inner_node-1);

    //初始化竞赛树
    for(int i=0;i<theNumberOfPlayers;++i){
        if(i<lowExt){
            ptr_.get[offset+i]=thePlayer[i];
        } else{
            ptr_.get[i-lowExt+theNumberOfPlayers-1]=thePlayer[i];
        }
    }

    //进行比赛
    
}

/*******************************************
*                 输者树的实现               *
/*******************************************/


#endif //TESK_WINNER_TREE_H
