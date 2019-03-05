//
// Created by jinqiu on 19-3-3.
//
#include "sort.h"

#include <time.h>

void produceRandomNumbers(int arr[],int len,int start,int end)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<len;++i){
        arr[i]=start+(rand()%(end-start));
    }
}

void print(int arr[],int len){
    for(int i=0;i<len;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    time_t c_start,c_end;
    //int arr[10]={2,33,44,66,7,1,0,34,45,23};
    int arr[100000];
    produceRandomNumbers(arr,100000,100,10000);

//    c_start=clock();
//    cout<<"BubbleSort:";
//    BubbleSort<int>(arr,100000);
//    //print(arr,10);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

//    c_start=clock();
//    cout<<"QuickSort:";
//    QuickSort<int>(arr,0,99999);
////    print(arr,1000);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

//    c_start=clock();
//    cout<<"InsertSort:";
//    InsertSort<int>(arr,100000);
////    print(arr,1000);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

//    c_start=clock();
//    cout<<"ShellSort:";
//    ShellSort<int>(arr,100000);
////    print(arr,1000);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

    c_start=clock();
    cout<<"SelectSort:";
    ShellSort<int>(arr,100000);
    print(arr,100);
    c_end=clock();
    cout<<c_end-c_start<<" ms"<<endl;

    return 0;
}
