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

    cout<<"=========>stack practice:"<<endl;
    ArrayStack<char> X(10);
    ArrayStack<char> Y(10);
    cout<<"访问a|b|c页面:"<<endl;
    X.push('a');
    X.push('b');
    X.push('c');
    cout<<"X:";
    X.print();
    cout<<"Y:";
    Y.print();
    cout<<"返回访问a:"<<endl;
    Y.push(X.pop());
    Y.push(X.pop());
    cout<<"X:";
    X.print();
    cout<<"Y:";
    Y.print();
    cout<<"返回访问b:"<<endl;
    X.push(Y.pop());
    cout<<"X:";
    X.print();
    cout<<"Y:";
    Y.print();
    cout<<"访问d:"<<endl;
    while(!Y.empty()){
        Y.pop();
    }
    X.push('d');
    cout<<"X:";
    X.print();
    cout<<"Y:";
    Y.print();

    return 0;
}