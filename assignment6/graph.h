//
// Created by jinqiu on 2019/3/13.
//

#ifndef TESK_GRAPH_H
#define TESK_GRAPH_H

#include <vector>
#include <algorithm>

#include "utils.h"
#include "queue.h"

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
    virtual bool exits_edge(int i,int j)=0;
    //插入边（i,j）
    virtual void insert_edge(const Edge<T> &edge)=0;
    //删除边
    virtual void erase_edge(int i, int j)=0;
    //返回顶点的度（只适用于无向图）
    virtual int degree(const int &top)=0;
    //返回顶点的入度
    virtual int in_degree(const int &top)=0;
    //返回顶点的出度
    virtual int out_degree(const int &top)=0;

    //有向图时返回true
    virtual bool directed()=0;
    //加权图时返回true
    virtual bool weighted()=0;
    //访问指定顶点的相邻顶点
    virtual VertexIterator<T> *iterator(int)=0;

public:
    /*******************************************
    *                  图的遍历                  *
    /*******************************************/
    //广度优先遍历
    virtual vector<T> bfs(int v)
    {
        vector<T> reach;
        ArrayQueue<int> q(10);
        reach.push_back(v);

        q.push(v);
        while(!q.empty()){
            //从队列中删除一个顶点
            int w=q.front();
            q.pop();

            //标记所有没有到达的邻接于顶点w的顶点
            VertexIterator<T> *iw=iterator(w);
            int u;
            //访问顶点w相邻顶点
            while ((u=iw->next())!=0){
                //u为没有到达过的顶点
                if(find(reach.begin(),reach.end(),u)==reach.end()){
                    q.push(u);
                    reach.push_back(u);
                }
            }
            delete iw;
        }

        return reach;
    }
    
    //深度优先遍历
    virtual vector<T> dfs(int v)
    {
        vector<T> reach;
        rdfs(v,reach);

        return reach;
    }

    //递归深度优先遍历
    void rdfs(int v,vector<T> &reach)
    {
        reach.push_back(v);
        VertexIterator<T> *iw=iterator(v);
        int u=0;
        //访问v的相邻顶点
        while((u=iw->next())!=0){
            //如果U是一个未遍历的顶点
            if(find(reach.begin(),reach.end(),u)==reach.end()){
                rdfs(u,reach);
            }
        }
        delete iw;
    }

    /*******************************************
    *                  最优路径                  *
    /*******************************************/
    //Dijkstra算法
    void dijkstra(int v)
    {

    }
};

#endif //TESK_GRAPH_H
