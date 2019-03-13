//
// Created by jinqiu on 19-3-12.
//
#include <initializer_list>

#include "priority_queue.h"

/**
 * �ϲ�K����������
 *
 * �㷨ԭ��
 * ����һ����СΪn*k�����鱣�����Ľ��
 * ����һ����СΪk����С�ѣ�����Ԫ��Ϊk�������е�ÿ������ĵ�һ��Ԫ��
 * �ظ����в���n*k�Σ�
 *  1��ÿ�δӶ���ȡ����СԪ�أ��Ѷ�Ԫ�أ���������������������
 *  2���öѶ�Ԫ�������������һԪ�ؽ��Ѷ�Ԫ���滻����
 *  3�����������Ԫ�ر�ȡ���ˣ����Ѷ�Ԫ���滻Ϊ�����ÿ���滻�Ѷ�Ԫ�غ����µ�����
 * */
struct MinHeapNode{
    int value_;
    int index_;
    int number_;
    MinHeapNode():value_(0),index_(0),number_(0){}
    MinHeapNode(int value,int index,int number):value_(value),
                                                index_(index),
                                                number_(number){}
    MinHeapNode(const MinHeapNode &other){
        value_=other.value_;
        index_=other.index_;
        number_=other.number_;
    }

    bool operator>(const MinHeapNode &theNode){
        if(this->value_>theNode.value_){
            return true;
        } else{
            return false;
        }
    }

    void operator=(MinHeapNode theNode){
        this->value_=theNode.value_;
        this->index_=theNode.index_;
        this->number_=theNode.number_;
    }
};

int *merge_K_array(int len,initializer_list<int *> arr)
{
    int size=arr.size();
    int *result=new int[len*size];

    MinHeap<MinHeapNode> min_heap(len);
    int i=0;
    for(auto it=arr.begin();it!=arr.end();++it,++i){
        MinHeapNode tmp(*(*it),0,i);
        min_heap.push(tmp);
    }

    auto it1=arr.begin();
    for(int j=0;j<len*size;++j){
        MinHeapNode tmp1=min_heap.pop();
        result[j]=tmp1.value_;

        int index=tmp1.index_+1;
        int number=tmp1.number_;
        if(tmp1.index_+1<len){
            MinHeapNode tmp2(*(*(it1+tmp1.number_)+tmp1.index_+1),
                             index,number);
            min_heap.push(tmp2);
        }

    }

    return result;
}
int main()
{
//    cout<<"=========>MaxHeap:"<<endl;
//    MaxHeap<int> max_heap(5);
//    max_heap.push(1);
//    max_heap.push(10);
//    max_heap.push(6);
//    max_heap.push(3);
//    max_heap.push(8);
//    max_heap.push(12);
//    max_heap.push(55);
//    max_heap.print();
//    cout<<"=========>"<<endl;
//    cout<<"size:"<<max_heap.size()<<endl;
//    cout<<"capacity:"<<max_heap.max_size()<<endl;
//    cout<<"front:"<<max_heap.front()<<endl;
//    cout<<"pop:"<<max_heap.pop()<<endl;
//    max_heap.print();
//
//    cout<<"=========>MinHeap:"<<endl;
//    MinHeap<int> min_heap(5);
//    min_heap.push(1);
//    min_heap.push(10);
//    min_heap.push(6);
//    min_heap.push(3);
//    min_heap.push(8);
//    min_heap.push(12);
//    min_heap.push(55);
//    min_heap.print();
//    cout<<"=========>"<<endl;
//    cout<<"size:"<<min_heap.size()<<endl;
//    cout<<"capacity:"<<min_heap.max_size()<<endl;
//    cout<<"front:"<<min_heap.front()<<endl;
//    cout<<"pop:"<<min_heap.pop()<<endl;
//    min_heap.print();

    cout<<"=========>merge_K_array:"<<endl;
    int len=5;
    int size=2;
    int arr1[5]={1,3,6,8,9};
    int arr2[5]={11,14,17,18,19};
    int * p=merge_K_array(5,{ arr1, arr2 });
    for(int i=0;i<len*size;++i){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
    delete[] p;

    return 0;
}