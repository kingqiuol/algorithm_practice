//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_LISTEDDIGRAPH_H
#define TESK_LISTEDDIGRAPH_H

#include "graph.h"
#include "listedWDigraph.h"

/*******************************************
*              图---邻接链表的实现            *
/*******************************************/

/*******************************************
*                  无权有向图                *
/*******************************************/
template <class T>
class listedDigraph:public Graph<T>
{
public:
    listedDigraph(int numberOfVertices=0):adj_list_(numberOfVertices){}
    ~listedDigraph(){}

    //返回图的顶点数
    int number_of_vertices(){return adj_list_.number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_list_.number_of_Edge();}
    //判断边（i,j）是否存在
    bool exits_edge(int i,int j){return adj_list_.exits_edge(i,j);}

    //插入边（i,j）
    void insert_edge(const Edge<T> &edge){ adj_list_.insert_edge(edge);}
    //删除边
    void erase_edge(int i, int j){adj_list_.erase_edge(i,j);}
    //返回顶点的度（只适用于无向图）
    int degree(const int &top){return adj_list_.degree(top);}
    //返回顶点的入度
    int in_degree(const int &top){return degree(top);}
    //返回顶点的出度
    int out_degree(const int &top){return degree(top);}

    //有向图时返回true
    bool directed(){return true;}
    //加权图时返回true
    bool weighted(){return false;}

    //访问指定顶点的相邻顶点
    VertexIterator<T> *iterator(int vertex){adj_list_.iterator(vertex);}

    //打印邻接矩阵
    void print(){adj_list_.print();}
private:
    listedWDigraph<T> adj_list_;
};

/*******************************************
*                  无权无向图                *
/*******************************************/
template <class T>
class listedGraph:public Graph<T>
{
public:
    listedGraph(int numberOfVertices=0):adj_list_(numberOfVertices){}
    ~listedGraph(){}

    //返回图的顶点数
    int number_of_vertices(){return adj_list_.number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_list_.number_of_Edge();}
    //判断边（i,j）是否存在
    bool exits_edge(int i,int j){return adj_list_.exits_edge(i,j);}

    //插入边（i,j）
    void insert_edge(const Edge<T> &edge)
    {
        adj_list_.insert_edge(edge);
        const Edge<T> temp(edge.index2_,
                           edge.index1_,
                           edge.weight_);

        adj_list_.insert_edge(temp);
    }
    
    //删除边
    void erase_edge(int i, int j)
    {
        adj_list_.erase_edge(i,j);
        adj_list_.erase_edge(j,i);
    }
    
    //返回顶点的度（只适用于无向图）
    int degree(const int &top){return adj_list_.get()[top].size();}
    //返回顶点的入度
    int in_degree(const int &top){return degree(top);}
    //返回顶点的出度
    int out_degree(const int &top){return degree(top);}

    //有向图时返回true
    bool directed(){return true;}
    //加权图时返回true
    bool weighted(){return false;}

    //访问指定顶点的相邻顶点
    VertexIterator<T> *iterator(int vertex){adj_list_.iterator(vertex);}

    //打印邻接矩阵
    void print(){adj_list_.print();}
private:
    listedWDigraph<T> adj_list_;
};

#endif //TESK_LISTEDDIGRAPH_H
