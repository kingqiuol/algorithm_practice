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
#include <cassert>

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
class listedWDigraph:public Graph<T>
{
private:
    typedef SingleList<ElementRegion<T>> list;
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

    if(-1==adj_list_[i].get_index(ElementRegion<T>(j))){
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
    if(index=adj_list_[i].get_index(ElementRegion<T>(j))==-1){
        ElementRegion<T> value(edge.index2_,edge.weight_);
        adj_list_[i].insert(0,value);
        ++edge_size_;
    }else{
        adj_list_[i].get(index).weight_=edge.weight_;
    }
}

template <class T>
void listedWDigraph<T>::erase_edge(int i, int j)
{
    if(i<0||j<0||i>=top_size_||j>=top_size_||i==j){
        ostringstream s;
        s << "(" << i << "," << j
          << ") is not a permissible edge";
        throw invalid_argument(s.str());
    }

    int index=adj_list_[i].get_index(ElementRegion<T>(j));
    if(-1!=index){
        adj_list_[i].erase(index);
        --edge_size_;
    }
}

template <class T>
int listedWDigraph<T>::degree(const int &top)
{
    cout<<"Directed Graph without Degree..."<<endl;
    exit(0);
}

template <class T>
int listedWDigraph<T>::in_degree(const int &top)
{
    if(top<0||top>=top_size_){
        throw invalid_argument("Vertex is't exit in graph!");
    }

    return adj_list_[top].size();
}

template <class T>
int listedWDigraph<T>::out_degree(const int &top)
{
    if(top<0||top>=top_size_){
        throw invalid_argument("Don't exit this vertices");
    }

    int sum=0;
    for(int i=0;i<top_size_;++i){
        if(-1!=adj_list_[i].get_index(ElementRegion<T>(top))){
            ++sum;
        }
    }

    return sum;
}

template <class T>
VertexIterator<T>* listedWDigraph<T>::iterator(int vertex)
{
    if(vertex<0||vertex>=top_size_){
        throw invalid_argument("Don't exit this vertices");
    }

    vector<T> theRow(top_size_,0);
    for(int i=0;i<adj_list_[vertex].size();++i){
        int index=adj_list_[vertex].get(i).vertex_;
        T weight=adj_list_[vertex].get(i).weight_;
        theRow[index]=weight;
    }

    return new VertexIterator<T>(theRow,0,top_size_,edge_size_);
}

template <class T>
void listedWDigraph<T>::print()
{
    for(int i=0;i<top_size_;++i){
        cout<<i<<":";
        for(int j=0;j<adj_list_[i].size();++j){
            cout<<adj_list_[i].get(j).vertex_<<"<"<<adj_list_[i].get(j).weight_<<"> -> ";
        }
        cout<<"NULL"<<endl;
    }
}

/*******************************************
*                  有权无向图                *
/*******************************************/
template <class T>
class listedWGraph:public Graph<T>
{
public:
    listedWGraph(int numberOfVertices=0):adj_list_(numberOfVertices){}
    ~listedWGraph(){}

    //返回图的顶点数
    int number_of_vertices(){return adj_list_.number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_list_.number_of_Edge();}
    //判断边（i,j）是否存在
    bool exits_edge(int i,int j){return adj_list_.exits_edge(i,j);}

    //插入边（i,j）
    void insert_edge(const Edge<T> &edge);
    //删除边
    void erase_edge(int i, int j);
    //返回顶点的度（只适用于无向图）
    int degree(const int &top){return adj_list_.get()[top].size();}
    //返回顶点的入度
    int in_degree(const int &top){return degree(top);}
    //返回顶点的出度
    int out_degree(const int &top){return degree(top);}

    //有向图时返回true
    bool directed(){return false;}
    //加权图时返回true
    bool weighted(){return true;}

    //访问指定顶点的相邻顶点
    VertexIterator<T> *iterator(int vertex);

    //打印邻接矩阵
    void print(){adj_list_.print();}
private:
    listedWDigraph<T> adj_list_;
};

template <class T>
void listedWGraph<T>::insert_edge(const Edge<T> &edge)
{
    adj_list_.insert_edge(edge);
    const Edge<T> temp(edge.index2_,
                       edge.index1_,
                       edge.weight_);

    adj_list_.insert_edge(temp);
}

template <class T>
void listedWGraph<T>::erase_edge(int i, int j)
{
    adj_list_.erase_edge(i,j);
    adj_list_.erase_edge(j,i);
}

template <class T>
VertexIterator<T>* listedWGraph<T>::iterator(int vertex)
{
    return adj_list_.iterator(vertex);
}

#endif //TESK_LISTEDWDIGRAPH_H

