//
// Created by jinqiu on 19-5-14.
//

#ifndef TESK_BACKTRACKING_H
#define TESK_BACKTRACKING_H


#include <cmath>
#include <iostream>
#include <algorithm>
#include<vector>
#include<string>

using namespace std;

/**
 * 回溯法（back tracking）
 *
 * （探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到
 * 某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为
 * 回溯法，而满足回溯条件的某个状态的点称为“回溯点”。
 *
 * 1、解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：
 * （1）路径：也就是已经做出的选择。
 * （2）选择列表：也就是你当前可以做的选择。
 * （3）结束条件：也就是到达决策树底层，无法再做选择的条件。
 *
 * 2、回溯算法的基本框架：
   result = []
   def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

 * 3、前序遍历的代码在进入某一个节点之前的那个时间点执行，后序遍历代码在离开某个节点之后的那
 * 个时间点执行。我们只要在递归之前做出选择，在递归之后撤销刚才的选择，就能正确得到每个节点的
 * 选择列表和路径。
*/

/*******************************************
*                 N 皇后问题                *
/*******************************************/
bool isValid(const vector<string> &board,const int &row,const int &col){
    int c=board[0].length();
    int r=board.size();
    for(int i=0;i<r;++i){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    // 检查右上方是否有皇后互相冲突
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < c; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // 检查左上方是否有皇后互相冲突
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}


void backtrack(vector<vector<string>> &res,
               vector<string> &board,const int &row){
    if(row==board.size()){
        res.push_back(board);
        return ;
    }

    int n=board[0].length();
    for(int i=0;i<n;++i){
        if(!isValid(board,row,i)){
            continue;
        }

        board[row][i]='Q';
        backtrack(res,board,row+1);
        board[row][i]='.';
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(res,board,0);

    return res;
}

/*******************************************
*                 0-1背包问题                *
/*******************************************/
struct element{
    int id;                 //元素标记
    double profitDensity;   //收益密度

    element(int theId=0,double theProfitDensity=0.0):
            id(theId),profitDensity(theProfitDensity){}
};

double capacity;
int numberOfObjects;
double *weight;                     //对象的重量
double *profit;                     //对象的收益
double weightOfCurrentPacking;
double profitFromCurrentPacking;
double maxProfitSoFar;

//背包界定函数
double profitBound(int currentLevel)
{
    //返回子树中最优节点上值的上界
    double remainingCapacity=capacity-weightOfCurrentPacking;
    double profitBound=profitFromCurrentPacking;

    //按照收益密度顺序填充剩余容量
    while(currentLevel<=numberOfObjects &&
          weight[currentLevel]<=remainingCapacity){
        remainingCapacity-=weight[currentLevel];
        profitBound+=profit[currentLevel];
        currentLevel++;
    }

    //取下一个对象的一部分
    if(currentLevel<=numberOfObjects){
        profitBound+=profit[currentLevel]/weight[currentLevel]*remainingCapacity;
    }

    return profitBound;
}

/*******************************************
*                  递归实现                  *
/*******************************************/
void rKnap(int currentLevel)
{
    //到达叶子节点
    if(currentLevel>numberOfObjects){
        maxProfitSoFar=profitFromCurrentPacking;
        return ;
    }

    //没有到达叶子节点
    if(weightOfCurrentPacking+weight[currentLevel]<=capacity){
        //搜索左子树
        weightOfCurrentPacking+=weight[currentLevel];
        profitFromCurrentPacking+=profit[currentLevel];
        rKnap(currentLevel+1);
        weightOfCurrentPacking-=weight[currentLevel];
        profitFromCurrentPacking-=profit[currentLevel];
    }

    if(profitBound(currentLevel+1)>maxProfitSoFar){
        rKnap(currentLevel+1);//搜索右子树
    }
}


//返回背包最优填充的收益值
double knapsack(double *theProfit,double *theWeight,
                int theNumberOfObjects,double theCapacity)
{
    //初始化全局变量
    capacity=theCapacity;
    numberOfObjects=theNumberOfObjects;
    weightOfCurrentPacking=0.0;
    profitFromCurrentPacking=0.0;
    maxProfitSoFar=0.0;

    //定义结构体存储收益密度
    element *q=new element[numberOfObjects];
    //存储收益密度
    for(int i=0;i<=numberOfObjects;++i){
        q[i-1]=element(i,theProfit[i]/theWeight[i]);
    }

    //按照收益密度递增排序
    std::sort(q,q+numberOfObjects,
              [](element e1,element e2)
              {return e1.profitDensity>e2.profitDensity;});

    //初始化剩余全局变量
    profit=new double[numberOfObjects+1];
    weight=new double[numberOfObjects+1];
    //按照收益密度递减顺序初始化收益和权重
    for(int i=1;i<=numberOfObjects;++i){
        profit[i]=theProfit[q[numberOfObjects-i].id];
        weight[i]=theWeight[q[numberOfObjects-i].id];
    }

    //计算最大收益
    rKnap(1);

    return maxProfitSoFar;
}





#endif //TESK_BACKTRACKING_H
