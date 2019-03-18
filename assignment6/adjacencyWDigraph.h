//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_ADJACENCYWDIGRAPH_H
#define TESK_ADJACENCYWDIGRAPH_H

#include "graph.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

/*******************************************
*              图---邻接矩阵的实现            *
/*******************************************/

/*******************************************
*                  有权有向图                *
/*******************************************/
template <class T>
class adjacencyWDigraph:public Graph<T>
{
public:
    adjacencyWDigraph(int top_size,int noEdge);
    ~adjacencyWDigraph(){}

    //获取邻接矩阵
    vector<T> &get(){return adj_mat_;}
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
    //VertexIterator<T> *iterator(int);

    //打印邻接矩阵
    void print();
private:
    vector<T> adj_mat_;//邻接矩阵
    int top_size_;//顶点的个数
    int edge_size_;//边的个数
    T noEdge_;//不存在边的填充值
};

template <class T>
adjacencyWDigraph<T>::adjacencyWDigraph(int top_size, int noEdge)
        :top_size_(top_size),noEdge_(noEdge),edge_size_(0)
{
    if(top_size_<=0){
        throw invalid_argument("number of vertices must be >= 0");
    }

    adj_mat_.resize(top_size_*top_size_);
    fill(adj_mat_.begin(),adj_mat_.end(),noEdge_);
}

template <class T>
bool adjacencyWDigraph<T>::exits_edge(int i,int j)
{
    if(i<0||j<0|| i>=top_size_||j>=top_size_||
            adj_mat_[i*top_size_+j]==noEdge_){
        return false;
    }else{
        return true;
    }
}

template <class T>
void adjacencyWDigraph<T>::insert_edge(const Edge<T> &edge)
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
        }
    }
    adj_mat_[pos]=edge.weight_;
}

template <class T>
void adjacencyWDigraph<T>::erase_edge(int i, int j)
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
int adjacencyWDigraph<T>::degree(const int &top)
{
    cout<<"Directed Graph without Degree..."<<endl;
    exit(0);
}

template <class T>
int adjacencyWDigraph<T>::in_degree(const int &top)
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

    return sum;
}

template <class T>
int adjacencyWDigraph<T>::out_degree(const int &top)
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
template <class T>
void adjacencyWDigraph<T>::print()
{
    for(int i=0;i<top_size_;++i){
        for(int j=0;j<top_size_;++j){
            cout<<adj_mat_[i*top_size_+j]<<" ";
        }
        cout<<endl;
    }
}

/*******************************************
*                  有权无向向图               *
/*******************************************/
template <class T>
class adjacencyWGraph:public Graph<T>
{
public:
    adjacencyWGraph(int top_size,int noEdge);
    ~adjacencyWGraph(){delete adj_mat_;}

    //获取邻接矩阵
    vector<T> &get(){return adj_mat_->get();}

    //返回图的顶点数
    int number_of_vertices(){return adj_mat_->number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_mat_->number_of_Edge();}
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
    bool directed(){return false;}
    //加权图时返回true
    bool weighted(){return true;}
    //访问指定顶点的相邻顶点
    //VertexIterator<T> *iterator(int);

    //打印邻接矩阵
    void print();
private:
    adjacencyWDigraph<T> *adj_mat_;
};

template <class T>
adjacencyWGraph<T>::adjacencyWGraph(int top_size, int noEdge)
{
    adj_mat_=new adjacencyWDigraph<T>(top_size,noEdge);
}

template <class T>
bool adjacencyWGraph<T>::exits_edge(int i, int j)
{
    return adj_mat_->exits_edge(i,j) || adj_mat_->exits_edge(j,i);
}

template <class T>
void adjacencyWGraph<T>::insert_edge(const Edge<T> &edge)
{
    adj_mat_->insert_edge(edge);
    Edge<T> edge1;
    edge1.index1_=edge.index2_;
    edge1.index2_=edge.index1_;
    edge1.weight_=edge.weight_;
    adj_mat_->insert_edge(edge1);
}

template <class T>
void adjacencyWGraph<T>::erase_edge(int i, int j)
{
    adj_mat_->erase_edge(i,j);
    adj_mat_->erase_edge(j,i);
}

template <class T>
int adjacencyWGraph<T>::degree(const int &top)
{
    int size=number_of_vertices();

    if(top<0 || top>=size){
        throw invalid_argument("top must be >0 0r <size(top<0 || top>=size)");
    }

    int sum=0;
    for(int i=0;i<size;++i){
        if(exits_edge(top,i)){
            ++sum;
        }
    }

    return sum;
}

template <class T>
int adjacencyWGraph<T>::in_degree(const int &top)
{
    return degree(top);
}

template <class T>
int adjacencyWGraph<T>::out_degree(const int &top)
{
    return degree(top);
}

template <class T>
void adjacencyWGraph<T>::print()
{
    int size=number_of_vertices();
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            cout<<get()[i*size+j]<<" ";
        }
        cout<<endl;
    }
}

/*******************************************
*                  无权有向向图               *
/*******************************************/
template <class T>
class adjacencyDigraph:public Graph<T>
{
public:
    adjacencyDigraph(int top_size,int noEdge);
    ~adjacencyDigraph(){delete adj_mat_;}

    //获取邻接矩阵
    vector<T> &get(){return adj_mat_->get();}

    //返回图的顶点数
    int number_of_vertices(){return adj_mat_->number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_mat_->number_of_Edge();}
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
    bool weighted(){return false;}

    //访问指定顶点的相邻顶点
    //VertexIterator<T> *iterator(int);

    //打印邻接矩阵
    void print();
private:
    adjacencyWDigraph<T> *adj_mat_;
};

template <class T>
adjacencyDigraph<T>::adjacencyDigraph(int top_size, int noEdge)
{
    adj_mat_=new adjacencyWDigraph<T>(top_size,noEdge);
}

template <class T>
bool adjacencyDigraph<T>::exits_edge(int i, int j)
{
    return adj_mat_->exits_edge(i,j);
}

template <class T>
void adjacencyDigraph<T>::insert_edge(const Edge<T> &edge)
{
    adj_mat_->insert_edge(edge);
}

template <class T>
void adjacencyDigraph<T>::erase_edge(int i, int j)
{
    adj_mat_->erase_edge(i,j);
}

template <class T>
int adjacencyDigraph<T>::degree(const int &top)
{
    cerr<<"Directed Graph without Degree..."<<endl;
    exit(0);
}

template <class T>
int adjacencyDigraph<T>::in_degree(const int &top)
{
    return adj_mat_->in_degree(top);
}

template <class T>
int adjacencyDigraph<T>::out_degree(const int &top)
{
    return adj_mat_->out_degree(top);
}

template <class T>
void adjacencyDigraph<T>::print()
{
    int size=number_of_vertices();
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            cout<<get()[i*size+j]<<" ";
        }
        cout<<endl;
    }
}

/*******************************************
*                  无权无向向图               *
/*******************************************/
template <class T>
class adjacencyGraph:public Graph<T>
{
public:
    adjacencyGraph(int top_size,int noEdge);
    ~adjacencyGraph(){delete adj_mat_;}

    //获取邻接矩阵
    vector<T> &get(){return adj_mat_->get();}

    //返回图的顶点数
    int number_of_vertices(){return adj_mat_->number_of_vertices();}
    //返回图的边数
    int number_of_Edge(){return adj_mat_->number_of_Edge();}
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
    bool directed(){return false;}
    //加权图时返回true
    bool weighted(){return false;}

    //访问指定顶点的相邻顶点
    //VertexIterator<T> *iterator(int);

    //打印邻接矩阵
    void print();
private:
    adjacencyWGraph<T> *adj_mat_;
};

template <class T>
adjacencyGraph<T>::adjacencyGraph(int top_size, int noEdge)
{
    adj_mat_=new adjacencyWGraph<T>(top_size,noEdge);
}

template <class T>
bool adjacencyGraph<T>::exits_edge(int i, int j)
{
    return adj_mat_->exits_edge(i,j);
}

template <class T>
void adjacencyGraph<T>::insert_edge(const Edge<T> &edge)
{
    adj_mat_->insert_edge(edge);
}

template <class T>
void adjacencyGraph<T>::erase_edge(int i, int j)
{
    adj_mat_->erase_edge(i,j);
}

template <class T>
int adjacencyGraph<T>::degree(const int &top)
{
    return adj_mat_->degree(top);
}

template <class T>
int adjacencyGraph<T>::in_degree(const int &top)
{
    return adj_mat_->in_degree(top);
}

template <class T>
int adjacencyGraph<T>::out_degree(const int &top)
{
    return adj_mat_->out_degree(top);
}

template <class T>
void adjacencyGraph<T>::print()
{
    int size=number_of_vertices();
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            cout<<get()[i*size+j]<<" ";
        }
        cout<<endl;
    }
}

#endif //TESK_ADJACENCYWDIGRAPH_H
