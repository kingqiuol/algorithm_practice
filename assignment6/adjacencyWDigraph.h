//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_ADJACENCYWDIGRAPH_H
#define TESK_ADJACENCYWDIGRAPH_H

#include "graph.h"

#include <iostream>
#include <vector>

using namespace std;

/*******************************************
*              图---邻接矩阵的实现             *
/*******************************************/

/*******************************************
*                  有权有向图                 *
/*******************************************/
template <class T>
class adjaceencyWDigraph:public Graph<T>
{
public:
    adjaceencyWDigraph();
    ~adjaceencyWDigraph({};


    //返回图的顶点数
    int number_of_vertices() ;
    //返回图的边数
    int number_of_Edge();
    //判断边（i,j）是否存在
    bool exits_edge(Edge<T> *);
    //插入边（i,j）
    void insert_edge(int,int);
    //删除边
    void erase_edge(int,int);
    //返回顶点的度（只适用于无向图）
    int degree(int);
    //返回顶点的入度
    int in_degree(int);
    //返回顶点的出度
    int out_degree(int);

    //有向图时返回true
    bool directed();
    //加权图时返回true
    bool weighted();
    //访问指定顶点的相邻顶点
    VertexIterator<T> *iterator(int);
private:
    vector<vector<T>> adj_mat_;//邻接矩阵
    int top_size_;//顶点的个数
    int edge_size_;//边的个数
    T noEdge_;//不存在的边
};

#endif //TESK_ADJACENCYWDIGRAPH_H
