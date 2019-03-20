//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_LISTEDWDIGRAPH_H
#define TESK_LISTEDWDIGRAPH_H

#include "graph.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

/*******************************************
*              图---邻接链表的实现            *
/*******************************************/

//定义加权图的两个元素的作用域：权重和顶点
template <class T>
struct ElementRegion{
public:
    T weight_;      //边的权重
    int vertex_;    //顶点

public:
    ElementRegion(){}

    ElementRegion(int vertex):vertex_(vertex),weight_(0){}

    ElementRegion(const int vertex,const T &weight)
            :vertex_(vertex),weight_(weight){}

    ElementRegion(const ElementRegion<T> &other){
        weight_=other.weight_;
        vertex_=other.vertex_;
    }

    bool operator==(const ElementRegion<T> &other)
    {
        return vertex_==other.vertex_;
    }
};

/*******************************************
*                  有权有向图                *
/*******************************************/
template <class T>
class listedWDigraph:public Graph
{
public:
    listedWDigraph(int numberOfVertices=0);
    ~listedWDigraph();

    //获取邻接矩阵
    list *get(){return adj_list_;}
    //返回图的顶点数
    int number_of_vertices(){return top_size_;}
    //返回图的边数
    int number_of_Edge(){return edge_size_;}
    //判断边（i,j）是否存在
    bool exits_edge(int i,int j);

    //插入边（i,j）
    void insert_edge(const Edge<T> &edge);
    //删除边
    void erase_edge(int i, int j);
    //返回顶点的度（只适用于无向图）
    int degree(const int &top);
    //返回顶点的入度
    int in_degree(const int &top);
    //返回顶点的出度
    int out_degree(const int &top);

    //有向图时返回true
    bool directed(){return true;}
    //加权图时返回true
    bool weighted(){return true;}

    //访问指定顶点的相邻顶点
    VertexIterator<T> *iterator(int vertex);

    //打印邻接矩阵
    void print();
private:
    typedef SingleList<ElementRegion<T>> list;
    list *adj_list_;        //邻接链表
    int top_size_;          //顶点的个数
    int edge_size_;         //边的个数
};

template <class T>
listedWDigraph<T>::listedWDigraph(int numberOfVertices)
        :top_size_(numberOfVertices),edge_size_(0)
{
    adj_list_=new list[top_size_];
}

template <class T>
listedWDigraph<T>::~listedWDigraph()
{
    if(adj_list_){
        delete[] adj_list_;
        adj_list_= nullptr;
    }
}

template <class T>
bool listedWDigraph<T>::exits_edge(int i, int j)
{
    if(i<0||j<0||i>=top_size_||j>=top_size_){
        return false;
    }

    if(-1==adj_list_->get_index(ElementRegion(j))){
        return false;
    }

    return true;
}

template <class T>
void listedWDigraph<T>::insert_edge(const Edge<T> &edge)
{
    int i=edge.index1_;
    int j=edge.index2_;
    if(i<0||j<0||i>=top_size_||j>=top_size_||i==j){
        ostringstream s;
        s << "(" << i << "," << j
          << ") is not a permissible edge";
        throw invalid_argument(s.str());
    }

    //不存在边（i,j）
    int index=0;
    if(index=adj_list_[i].get_index(j)==-1){
        ElementRegion<T> value(edge.index2_,edge.weight_);
        adj_list_[i].insert(0,value);
        ++edge_size_;
    }else{
        adj_list_[i].get(index).weight_=edge.weight_;
    }
}

#endif //TESK_LISTEDWDIGRAPH_H

