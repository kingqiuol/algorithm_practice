//
// Created by jinqiu on 19-3-10.
//

#include "binary_tree.h"

int main()
{
    cout<<"=========>ArrayBTree:"<<endl;
    ArrayBTree<int> atree(20);
    atree.insert(1);
    atree.insert(3);
    atree.insert(9);
    atree.insert(2);
    atree.insert(5);
    atree.print();
    cout<<"size:"<<atree.size()<<endl;
    cout<<"capacity:"<<atree.max_size()<<endl;
    cout<<"find:"<<atree.find(9)<<endl;
    cout<<"=========>"<<endl;
//    atree.erase(9);
//    atree.print();
//    atree.set(2,8);
//    atree.print();
//    cout<<"get(2):"<<atree.get(2)<<endl;
    cout<<"=========>"<<endl;
    int pre=0,preindex=0;
    atree.predecessor(2,pre,preindex);
    int next=0,nextindex=0;
    atree.successor(2,next,nextindex);
    cout<<pre<<":"<<preindex<<"->"<<atree.get(2)<<":"<<2
        <<"->"<<next<<":"<<nextindex<<endl;
    cout<<"=========>"<<endl;
    cout<<"preOrder:";
    atree.preOrder() ;
    cout<<endl;
    cout<<"inOrder:";
    atree.inOrder() ;
    cout<<endl;
    cout<<"postOrder:";
    atree.postOrder() ;
    cout<<endl;
    cout<<"levelOrder:"<<endl;;
    atree.levelOrder();

    return 0;
}