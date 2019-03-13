//
// Created by jinqiu on 2019/3/13.
//

#ifndef TESK_GRAPH_H
#define TESK_GRAPH_H

template <class T>
class Graph
{
public:
    virtual ~Graph(){}

    //返回图的顶点数
    virtual int number_of_vertices() =0;
    //返回图的边数
    virtual int number_of_Edge()=0;
    //判断边（i,j）是否存在
    virtual bool exits_edge(edge<T> *)=0;
    //插入边（i,j）
    virtual void insert_edge(int,int)=0;
    //删除边
    virtual void erase_edge(int,int)=0;
    //返回顶点的度（只适用于无向图）
    virtual int degree(int)=0;
    //返回顶点的入度
    virtual int in_degree(int)=0;
    //返回顶点的出度
    virtual int out_degree(int)=0;

    //有向图时返回true
    virtual bool directed()=0;
    //加权图时返回true
    virtual bool weighted()=0;
    //访问指定顶点的相邻顶点
    virtual vertex_iterator<T> *iterator(int)=0;
};

#endif //TESK_GRAPH_H
