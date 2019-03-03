//
// Created by jinqiu on 19-3-2.
//

#include "stack.h"

int main()
{
    cout<<"=========>array stack:"<<endl;
    ArrayStack<int> array_stack(10);
    array_stack.push(0);
    array_stack.push(1);
    array_stack.push(2);
    array_stack.print();
    cout<<"size:"<<array_stack.size()<<endl;
    cout<<array_stack.top()<<endl;
    cout<<array_stack.pop()<<endl;
    array_stack.print();

    cout<<"=========>list stack:"<<endl;
    ListStack<int> list_stack;
    list_stack.push(0);
    list_stack.push(1);
    list_stack.push(2);
    list_stack.print();
    cout<<"size:"<<list_stack.size()<<endl;
    cout<<list_stack.top()<<endl;
    cout<<list_stack.pop()<<endl;
    list_stack.print();


    return 0;
}