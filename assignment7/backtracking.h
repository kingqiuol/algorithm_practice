//
// Created by jinqiu on 19-5-14.
//

#ifndef TESK_BACKTRACKING_H
#define TESK_BACKTRACKING_H


#include <cmath>
#include <iostream>
#include <algorithm>

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
