//
// Created by jinqiu on 19-3-3.
//

#ifndef TESK_SORT_H
#define TESK_SORT_H

#include <iostream>

using namespace std;

/*******************************************
*                  交换排序                 *
*******************************************/
//1、冒泡排序
template <class T>
void BubbleSort(T arr[],int len)
{
    for(int i=0;i<len;++i){
        for(int j=0;j<len-1-i;++j){
            if(arr[j]>arr[j+1]){
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//2、快速排序
template <class T>
void QuickSort(T arr[],int left,int right)
{
    int i=left;
    int j=right;
    T temp=arr[i];

    if (i<j){
        while(i<j) {
            while (i < j && temp <= arr[j])
                --j;
            if (i < j) {
                arr[i] = arr[j];
                ++i;
            }
            while (i < j && temp > arr[i])
                ++i;
            if (i < j) {
                arr[j] = arr[i];
                --j;
            }
        }

        arr[i]=temp;
        QuickSort(arr,left,i-1);
        QuickSort(arr,i+1,right);
    }
}

/*******************************************
*                  插入排序                 *
*******************************************/
//1、插入排序
template <class T>
void InsertSort(T arr[],int len)
{
    for(int i=1;i<len;++i){
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=temp;
    }
}

//2、希尔排序
template <class T>
void ShellSort(T arr[],int len)
{
    for (int gap = len / 3; gap > 0; gap /= 2){
        for (int i = gap; i < len; ++i){
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j]>temp){
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}

/*******************************************
*                  选择排序                 *
*******************************************/
//1、选择排序
template <class T>
void SelectSort(T arr[],int len)
{
    for (int i = 0; i < len - 1; ++i){
        int min = i;
        for (int j = i + 1; j < len; ++j){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

//2、堆排序
//调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）
template <class T>
void adjust_heap(T arr[], int i, int len)
{
    int temp = arr[i];//取出当前元素
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1){//从i结点的左子结点开始，也就是2i+1处开始
        if (k + 1 < len && arr[k] < arr[k + 1]){//如果左子结点小于右子结点，k指向右子结点
            ++k;
        }
        if (arr[k] > temp){//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换)
            arr[i] = arr[k];
            i = k;
        }
        else{
            break;
        }
    }
    arr[i] = temp;//将temp值放到最终的位置
}

template <class T>
void swap(T arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

//http://www.cnblogs.com/chengxiao/p/6129630.html
template <class T>
void HeapSort(T arr[], int len)
{
    //1、构建最大堆
    for (int i = len/2 - 1; i >= 0; i--){
        //从第一个非叶子节点从上往下，从右至左调整
        adjust_heap(arr, i, len);
    }

    //2、调整堆结构+交换堆顶元素与末尾元素
    for(int j=len-1;j>0;--j){
        swap(arr,0,j);
        adjust_heap(arr,0,j);
    }
}

/*******************************************
*                  归并排序                 *
*******************************************/
//1、归并排序
template <class T>
void MergeSort(T arr[],int len)
{

}

/*******************************************
*           线性时间非比较类排序              *
*******************************************/
//1、计数排序
template <class T>
void CountingSort(T arr[],int len)
{

}

//2、桶排序
template <class T>
void BucketSort(T arr[],int len)
{

}

//3、基数排序
template <class T>
void RadixSort(T arr[],int len)
{

}


#endif //TESK_SORT_H
