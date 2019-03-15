//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_ADJACENCYWDIGRAPH_H
#define TESK_ADJACENCYWDIGRAPH_H

#include "graph.h"

#include <iostream>
#include <vector>
#include <exception>
#include <sstream>

using namespace std;

/*******************************************
*              图---邻接矩阵的实现            *
/*******************************************/

/*******************************************
*                  有权有向图                *
/*******************************************/
template <class T>
class adjaceencyWDigraph:public Graph<T>
{
public:
    adjaceencyWDigraph(int top_size,int noEdge);
    ~adjaceencyWDigraph(){}


    //返回图的顶点数
    int number_of_vertices(){return top_size_;}
    //返回图的边数
    int number_of_Edge(){return edge_size_;}
    //判断边（i,j）是否存在
    bool exits_edge(int i,int j);
    //插入边（i,j）
    void insert_edge(Edge<T> &edge);
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
    VertexIterator<T> *iterator(int);
private:
    vector<T> adj_mat_;//邻接矩阵
    int top_size_;//顶点的个数
    int edge_size_;//边的个数
    T noEdge_;//不存在边的填充值
};

template <class T>
adjaceencyWDigraph<T>::adjaceencyWDigraph(int top_size, int noEdge)
        :top_size_(top_size),noEdge_(noEdge),edge_size_(0)
{
    if(top_size_<=0){
        throw invalid_argument("number of vertices must be >= 0");
    }

    adj_mat_.resize(top_size_*top_size_);
    fill(adj_mat_.begin(),adj_mat_.end(),noEdge_);
}

template <class T>
bool adjaceencyWDigraph<T>::exits_edge(int i,int j)
{
    if(i<0||j<0|| i>=top_size_||j>=top_size_||
            adj_mat_[i*top_size_+j]==noEdge_){
        return false;
    }else{
        return true;
    }
}

template <class T>
void adjaceencyWDigraph<T>::insert_edge(Edge<T> &edge)
{
    int i=edge.index1_;
    int j=edge.index2_;
    if(i<0||j<0||i>=top_size_||j>=top_size_||i==j){
        ostringstream s;
        s << "(" << i << "," << j
          << ") is not a permissible edge";
        throw invalid_argument(s.str());
    }

    int pos=i*top_size_+j;

    if(adj_mat_[pos]==noEdge_){
        if(edge.weight_==noEdge_){
            return ;
        }else{
            ++edge_size_;
        }
    }else{
        if(edge.weight_==noEdge_){
            --edge_size_;
            return ;
        }
    }
    adj_mat_[pos]=edge.weight_;
}

template <class T>
void adjaceencyWDigraph<T>::erase_edge(int i, int j)
{
    if(i<0||j<0||j>=top_size_||i>=top_size_){
        ostringstream s;
        s<<"i:"<<i<<",j:"<<j
         <<"must be (i<0||j<0||j>=top_size_||i>=top_size_)";
        throw invalid_argument(s.str());
    }

    int pos=i*top_size_+j;
    if(adj_mat_[pos]==noEdge_){
        return ;
    }
    adj_mat_[pos]=noEdge_;
    --edge_size_;
}

template <class T>
int adjaceencyWDigraph<T>::degree(const int &top)
{
    cerr<<"Directed Graph without Degree..."<<endl;
    exit(0);
}

template <class T>
int adjaceencyWDigraph<T>::in_degree(const int &top)
{
    if(top<0||top>=top_size_){
        throw invalid_argument("Don't exit this vertices");
    }

    int sum=0;
    int i=0;
    while(i<top_size_){
        sum+=adj_mat_[i*top_size_+top]==noEdge_?0:1;
        ++i;
    }

    return 0;
}

template <class T>
int adjaceencyWDigraph<T>::out_degree(const int &top)
{
    if(top<0||top>=top_size_){
        throw invalid_argument("Don't exit this vertices");
    }

    int sum=0;
    int j=0;
    while(j<top_size_){
        sum+=adj_mat_[top*top_size_+j]==noEdge_?0:1;
        ++j;
    }

    return sum;
}

#endif //TESK_ADJACENCYWDIGRAPH_H
