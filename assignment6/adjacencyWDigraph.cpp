//
// Created by jinqiu on 19-3-14.
//

#include "adjacencyWDigraph.h"

int main()
{
    cout<<"========>有权有向图："<<endl;
    adjacencyWDigraph<float> wdg(4,0);
    wdg.insert_edge(Edge<float >(0,1,2.5));
    wdg.insert_edge(Edge<float >(0,2,1.5));
    wdg.insert_edge(Edge<float>(1,2,1.15));
    wdg.insert_edge(Edge<float>(2,3,2.5));
    wdg.insert_edge(Edge<float>(3,0,2.5));
    wdg.insert_edge(Edge<float>(3,1,2.5));
    wdg.print();
    cout<<"edge size:"<<wdg.number_of_Edge()<<endl;
    cout<<"top size:"<<wdg.number_of_vertices()<<endl;
    wdg.erase_edge(0,1);
    wdg.print();
    //wdg.degree(1);
    cout<<"in_degree:"<<wdg.in_degree(1)<<endl;
    cout<<"out_degree:"<<wdg.out_degree(1)<<endl;

    cout<<"========>有权无向图："<<endl;
    adjacencyWGraph<float> wg(4,0);
    wg.insert_edge(Edge<float >(0,1,1.5));
    wg.insert_edge(Edge<float >(0,2,1.5));
    wg.insert_edge(Edge<float>(1,2,1.5));
    wg.insert_edge(Edge<float>(2,3,1.5));
    wg.insert_edge(Edge<float>(3,0,1.5));
    wg.insert_edge(Edge<float>(3,1,1.5));
    wg.print();
    cout<<"edge size:"<<wg.number_of_Edge()<<endl;
    cout<<"top size:"<<wg.number_of_vertices()<<endl;
    wg.erase_edge(0,1);
    wg.print();
    //wdg.degree(1);
    cout<<"in_degree:"<<wg.in_degree(1)<<endl;
    cout<<"out_degree:"<<wg.out_degree(1)<<endl;

    cout<<"========>无权有向图："<<endl;
    adjacencyDigraph<float> dg(4,0);
    dg.insert_edge(Edge<float >(0,1));
    dg.insert_edge(Edge<float >(0,2));
    dg.insert_edge(Edge<float>(1,2));
    dg.insert_edge(Edge<float>(2,3));
    dg.insert_edge(Edge<float>(3,0));
    dg.insert_edge(Edge<float>(3,1));
    dg.print();
    cout<<"edge size:"<<dg.number_of_Edge()<<endl;
    cout<<"top size:"<<dg.number_of_vertices()<<endl;
    dg.erase_edge(0,1);
    dg.print();
    //wdg.degree(1);
    cout<<"in_degree:"<<dg.in_degree(1)<<endl;
    cout<<"out_degree:"<<dg.out_degree(1)<<endl;

    cout<<"========>无权无向图："<<endl;
    adjacencyGraph<float> g(4,0);
    g.insert_edge(Edge<float >(0,1));
    g.insert_edge(Edge<float >(0,2));
    g.insert_edge(Edge<float>(1,2));
    g.insert_edge(Edge<float>(2,3));
    g.insert_edge(Edge<float>(3,0));
    g.insert_edge(Edge<float>(3,1));
    g.print();
    cout<<"edge size:"<<g.number_of_Edge()<<endl;
    cout<<"top size:"<<g.number_of_vertices()<<endl;
    g.erase_edge(0,1);
    g.print();
    //wdg.degree(1);
    cout<<"in_degree:"<<g.in_degree(1)<<endl;
    cout<<"out_degree:"<<g.out_degree(1)<<endl;

    return 0;
}
