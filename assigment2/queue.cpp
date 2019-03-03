//
// Created by jinqiu on 19-3-3.
//

#include "queue.h"

int main()
{
    cout<<"=========>ArrayQueue:"<<endl;
    ArrayQueue<int> array_queue;
    for(int i=0;i<12;i++){
        array_queue.push(i);
    }
    array_queue.print();
    cout<<"capacity:"<<array_queue.max_size()<<endl;
    cout<<"size:"<<array_queue.size()<<endl;
    cout<<"front:"<<array_queue.front()<<endl;
    cout<<"back:"<<array_queue.back()<<endl;
    cout<<"pop:"<<array_queue.pop()<<endl;
    array_queue.print();

    cout<<"=========>ListQueue:"<<endl;
    ListQueue<int> list_queue;
    for(int i=0;i<12;++i){
        list_queue.push(i);
    }
    list_queue.print();
    cout<<"front:"<<list_queue.front()<<endl;
    cout<<"back:"<<list_queue.back()<<endl;
    cout<<"pop:"<<list_queue.pop()<<endl;
    list_queue.print();
    return 0;
}

