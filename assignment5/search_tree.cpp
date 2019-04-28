//
// Created by jinqiu on 19-4-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "search.h"
#include "search_tree.h"

using namespace std;

int main()
{
    BinarySearchTree<int,int> bstree;
    bstree.insert(make_pair(9,4));
    bstree.insert(make_pair(1,4));
    bstree.insert(make_pair(11,5));
    bstree.insert(make_pair(4,4));
    bstree.insert(make_pair(90,4));
    cout<<"size:"<<bstree.size()<<endl;
    bstree.erase(1);
    cout<<"size:"<<bstree.size()<<endl;
    pair<const int,int> *tmp=bstree.find(11);
    cout<<"find 11:"<<tmp->first<<"->"<<tmp->second<<endl;
    bstree.ascend();

    IndexBinarySearchTree<int,int> ibstree;
    ibstree.insert(make_pair(9,4));
    ibstree.insert(make_pair(1,4));
    ibstree.insert(make_pair(11,5));
    ibstree.insert(make_pair(4,4));
    ibstree.insert(make_pair(10,4));
    ibstree.insert(make_pair(90,4));
    cout<<"size:"<<ibstree.size()<<endl;
    ibstree.erase(1);
    cout<<"size:"<<ibstree.size()<<endl;
    pair<const int,int> *tmp1=ibstree.find(11);
    cout<<"find 11:"<<tmp1->first<<"->"<<tmp1->second<<endl;
    ibstree.ascend();

    return 0;
}