//
// Created by jinqiu on 19-3-13.
//

#ifndef TESK_UTILS_H
#define TESK_UTILS_H

template <class T>
class Edge
{
public:
    virtual ~Edge(){}
    //返回一个边的第一个顶点
    virtual int vertex1() const = 0;
    //返回边的第二个顶点
    virtual int vertex2() const = 0;
    //返回边的权重
    virtual T weight() const = 0;
};

template <class T>
class VertexIterator
{
public:
    virtual ~VertexIterator() {}
    //返回该顶点的下一个顶点
    virtual int next() = 0;
    //如果为加权图，返回权w的下一个顶点，
    virtual int next(T&) = 0;
};


#endif //TESK_UTILS_H
