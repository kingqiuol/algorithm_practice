//
// Created by jinqiu on 19-3-14.
//

#ifndef TESK_LISTEDDIGRAPH_H
#define TESK_LISTEDDIGRAPH_H

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

#endif //TESK_LISTEDDIGRAPH_H
