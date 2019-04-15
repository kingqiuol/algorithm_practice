//
// Created by jinqiu on 19-4-15.
//

#ifndef TESK_WINNER_TREE_H
#define TESK_WINNER_TREE_H

#include<iostream>
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
    //最底层内部节点的个数
    
    //最左侧第一个竞赛者的下标的偏移量
    int offset=2*(theNumberOfPlayers-floor(log2(theNumberOfPlayers-1)))-1;
    for(int i=0;i<theNumberOfPlayers;++i){

        ptr_.get[offset+i]=thePlayer[i];
    }
}

/*******************************************
*                 输者树的实现               *
/*******************************************/


#endif //TESK_WINNER_TREE_H
