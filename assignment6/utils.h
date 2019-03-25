 //
// Created by jinqiu on 19-3-13.
//

#ifndef TESK_UTILS_H
#define TESK_UTILS_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Edge
{
public:
    Edge():index1_(0),index2_(0),weight_(0){}
    Edge(int index1,int index2,T weight=1): index1_(index1),
                                          index2_(index2),
                                          weight_(weight){}
    Edge(Edge<T> &other):index1_(other.index1_),index2_(other.index2_),
                         weight_(other.weight_){}

    ~Edge(){}
    //返回一个边的第一个顶点
    int vertex1() {return index1_;}
    //返回边的第二个顶点
    int vertex2() {return index2_;}
    //返回边的权重
    T weight() {return weight_;}

public:
    int index1_,index2_;
    T weight_;
};

template <class T>
class VertexIterator
{
public:
    VertexIterator(vector<T> &theRow,T theNoEdge,int numberOfVertices)
            :theRow_(theRow),
             noEdge_(theNoEdge),
             top_size_(numberOfVertices),
             currentVertex_(0){}

    ~VertexIterator() {}

    //获取顶点的个数
    int get_vertex_size(){return top_size_;}

    vector<T> get_adjacent_vertex(){return theRow_;}

    //返回该顶点的下一个顶点
    int next()
    {
        //搜索当前节点的下一个节点
        for(int j=currentVertex_;j<top_size_;++j){
            if(theRow_[j]!=noEdge_){
                currentVertex_=j+1;
                return j;
            }
        }

        //如果未搜索到下一个节点，返回0
        currentVertex_=top_size_;
        return 0;
    }

    //如果为加权图，返回权w的下一个顶点，
    int next(T& weights)
    {
        //搜索当前节点的下一个节点,并将当前边的权重传出
        for(int j=currentVertex_;j<top_size_;++j){
            if(theRow_[j]!=noEdge_){
                currentVertex_=j+1;
                weights=theRow_[j];
                return j;
            }
        }

        //如果未搜索到下一个节点，返回0
        currentVertex_=top_size_;
        return 0;
    }

private:
    vector<T> theRow_;      //邻接矩阵的行
    T noEdge_;              //不存在边的填充值
    int top_size_;          //顶点总数
    int currentVertex_;     //当前顶点
};


#endif //TESK_UTILS_H
