//
// Created by jinqiu on 2019/4/28.
//
#include <iostream>
#include "balanced_search_tree.h"

using namespace std;

int main()
{
//    cout<<"===>AVLSearchTree:"<<endl;
//    AVLSearchTree<int,int> avl;
//    avl.insert(make_pair(3,1));
//    avl.insert(make_pair(2,1));
//    avl.insert(make_pair(1,1));
//    avl.insert(make_pair(14,1));
//    avl.insert(make_pair(13,1));
//    avl.insert(make_pair(10,1));
//    avl.insert(make_pair(4,1));
//    avl.ascend();
//    cout<<"size:"<<avl.size()<<endl;
//    pair<const int,int> *pair1=avl.find(4);
//    cout<<"find 4:"<<pair1->first<<"->"<<pair1->second<<endl;
//    avl.erase(4);
//    avl.ascend();
//    cout<<"size:"<<avl.size()<<endl;

    cout<<"===>RBSearchTree:"<<endl;
    RBSearchTree<int,int> rb;
    rb.insert(make_pair(3,1));
//    rb.insert(make_pair(2,1));
//    rb.insert(make_pair(1,1));
//    rb.insert(make_pair(14,1));
//    rb.insert(make_pair(13,1));
//    rb.insert(make_pair(10,1));
//    rb.insert(make_pair(4,1));
//    rb.ascend();

    return 0;
}