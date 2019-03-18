//
// Created by jinqiu on 19-3-13.
//

#ifndef TESK_UTILS_H
#define TESK_UTILS_H

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
    ~VertexIterator() {}
    //返回该顶点的下一个顶点
    int next() ;
    //如果为加权图，返回权w的下一个顶点，
    int next(T&);
};


#endif //TESK_UTILS_H
