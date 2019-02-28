//
// Created by jinqiu on 19-2-27.
//

#include "list.h"

int main()
{
    //单向链表测试
    cout<<"================>单向链表："<<endl;
    SingleList<int> list1;
    list1.insert(0,1);
    list1.insert(0,3);
    list1.insert(1,2);
    list1.insert(2,7);
    list1.print();
    //list1.erase(1);
    //list1.print();
    cout<<"get(0):"<<list1.get(0)<<endl;
    list1.set(0,10);
    list1.print();
    list1.reverse();
    list1.print();
    cout<<"===>sort():";
    list1.sort();
    list1.print();


    //
    return 0;
}

