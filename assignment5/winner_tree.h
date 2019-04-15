//
// Created by jinqiu on 19-4-15.
//

#ifndef TESK_WINNER_TREE_H
#define TESK_WINNER_TREE_H

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
    CompeleteWinnerTree();
    ~CompeleteWinnerTree();

    //使用数组thePlayer初始化竞赛树
    void initialize(T *thePlayer,int theNumberOfPlayers);
    //返回赢着的索引
    int winner() const;
    //在竞赛这改变后，重新进行竞赛
    void rePlay(int thePlayer);
};



/*******************************************
*                 输者树的实现               *
/*******************************************/


#endif //TESK_WINNER_TREE_H
