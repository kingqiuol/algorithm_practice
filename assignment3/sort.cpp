//
// Created by jinqiu on 19-3-3.
//
#include "sort.h"

void print(int arr[],int len){
    for(int i=0;i<10;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int arr[10]={2,33,44,66,7,1,0,34,45,23};

//    cout<<"BubbleSort:";
//    BubbleSort<int>(arr,10);
//    print(arr,10);

//    cout<<"QuickSort:";
//    QuickSort<int>(arr,0,9);
//    print(arr,10);

    cout<<"InsertSort:";
    InsertSort<int>(arr,10);
    print(arr,10);

    return 0;
}
