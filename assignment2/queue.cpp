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

    cout<<"=========>CyclicQueue:"<<endl;
    CyclicQueue<int> cyclic_queue(10);
    for(int i=0;i<10;++i){
        cyclic_queue.push(i);
    }
    cyclic_queue.print();
    cyclic_queue.push(11);
    cyclic_queue.print();
    cout<<"max size:"<<cyclic_queue.max_size()<<endl;
    cout<<"size:"<<cyclic_queue.size()<<endl;
    cout<<"front:"<<cyclic_queue.front()<<endl;
    cout<<"back:"<<cyclic_queue.back()<<endl;
    cout<<"pop:"<<cyclic_queue.pop()<<endl;
    cyclic_queue.print();

    CyclicQueue<int> cyclic_queue1(10);
    for(int i=0;i<10;++i){
        cyclic_queue1.push(i);
    }
    cyclic_queue1.print();
    cyclic_queue1.pop();
    cyclic_queue1.pop();
    cyclic_queue1.print();
    cyclic_queue1.push(19);
    cyclic_queue1.push(20);
    cout<<"size:"<<cyclic_queue1.size()<<endl;
    cyclic_queue1.print();



    return 0;
}

