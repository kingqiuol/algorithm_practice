//
// Created by jinqiu on 19-3-14.
//

#include "listedDigraph.h"

int main()
{
    cout<<"========>listedDigraph："<<endl;
    listedWDigraph<float> ldg(4);
    ldg.insert_edge(Edge<float >(0,1));
    ldg.insert_edge(Edge<float >(0,2));
    ldg.insert_edge(Edge<float>(1,2));
    ldg.insert_edge(Edge<float>(2,3));
    ldg.insert_edge(Edge<float>(3,0));
    ldg.insert_edge(Edge<float>(3,1));
    ldg.print();
    cout<<"edge size:"<<ldg.number_of_Edge()<<endl;
    cout<<"top size:"<<ldg.number_of_vertices()<<endl;
//    lwdg.erase_edge(0,1);
//    lwdg.print();
    //lwdg.degree(1);
    cout<<"in_degree:"<<ldg.in_degree(1)<<endl;
    cout<<"out_degree:"<<ldg.out_degree(1)<<endl;
    vector<float > bfs=ldg.bfs(0);
    for(auto &c:bfs){
        cout<<c<<" ";
    }
    cout<<endl;
    vector<float > dfs=ldg.dfs(0);
    for(auto &c:dfs){
        cout<<c<<" ";
    }
    cout<<endl;

    cout<<"========>listedGraph："<<endl;
    listedGraph<float> lg(4);
    lg.insert_edge(Edge<float >(0,1));
    lg.insert_edge(Edge<float >(0,2));
    lg.insert_edge(Edge<float>(1,2));
    lg.insert_edge(Edge<float>(2,3));
    lg.insert_edge(Edge<float>(3,0));
    lg.insert_edge(Edge<float>(3,1));
    lg.print();
    cout<<"edge size:"<<lg.number_of_Edge()<<endl;
    cout<<"top size:"<<lg.number_of_vertices()<<endl;
    lg.erase_edge(0,1);
    lg.print();
    lg.degree(1);
    cout<<"in_degree:"<<lg.in_degree(1)<<endl;
    cout<<"out_degree:"<<lg.out_degree(1)<<endl;
    vector<float > bfs1=lg.bfs(0);
    for(auto &c:bfs1){
        cout<<c<<" ";
    }
    cout<<endl;
    vector<float > dfs1=lg.dfs(0);
    for(auto &c:dfs1){
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}