//
// Created by jinqiu on 19-3-3.
//

#ifndef TESK_SORT_H
#define TESK_SORT_H

#include <iostream>
#include <algorithm>
#include "list.h"

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
template <class T>
void merge(T arr[], int start, int mid, int end)
{
    int *tmp = new T[end - start + 1];// tmp是汇总2个有序区的临时区域
    int i = start;// 第1个有序区的索引
    int j = mid + 1;// 第2个有序区的索引
    int k = 0; // 临时区域的索引

    while (i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }
        else{
            tmp[k++] = arr[j++];
        }
    }

    while (i <= mid){
        tmp[k++] = arr[i++];
    }

    while (j <= end){
        tmp[k++] = arr[j++];
    }

    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        arr[start + i] = tmp[i];

    delete[] tmp;
}

template <class T>
void merge_sort(T arr[], int start, int end)
{
    if (arr == NULL || start >= end){
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid, end);

    merge(arr, start, mid, end);
}

//1、归并排序
template <class T>
void MergeSort(T arr[], int len)
{
    int start = 0;
    int end = len - 1;
    merge_sort(arr, start, end);
}

/*******************************************
*           线性时间非比较类排序              *
*******************************************/
//1、计数排序
template <class T>
void CountingSort(T arr[], int len)
{
    // 计算最大最小值
    auto it = minmax_element(arr, arr + len);
    T min = *it.first;
    T max = *it.second;
    int R = max - min + 1;

    // 1. 计算频率，在需要的数组长度上额外加1
    T *count = new T[R]();
    for (int i = 0; i < len; ++i){
        // 使用加1后的索引，有重复的该位置就自增
        count[arr[i] - min + 1] += 1;
    }

    // 2. 频率 -> 元素的开始索引
    for (int i = 0; i < R; ++i){
        count[i + 1] += count[i];
    }

    // 3. 元素按照开始索引分类，用到一个和待排数组一样大临时数组存放数据
    T *tmp = new T[len];
    for (int i = 0; i < len; ++i){
        tmp[count[arr[i] - min]++] = arr[i];
    }

    // 4. 数据回写
    copy(tmp, tmp + len, arr);

    delete[] count;
    delete[] tmp;
}

// 映射函数，将值转换为应存放到的桶数组的索引
template <class T>
int toBucketIndex(T value,int maxValue,int len)
{
    return (value*len)/(maxValue+1);
}

//2、桶排序
template <class T>
void BucketSort(T arr[],int len)
{
    // 建立桶，个数和待排序数组长度一样
    SingleList<T> *bucket=new SingleList<T>[len]();

    // 待排序数组中的最大值
    int maxValue=*max_element(arr,arr+len);
    // 根据每个元素的值，分配到对应范围的桶中
    for (int i=0;i<len;++i){
        int index=toBucketIndex(arr[i],maxValue,len);
        bucket[index].insert(0,arr[i]);
    }

    // 对每个非空的桶排序，排序后顺便存入临时的List，则list中已经有序
    T tmp[len];
    int j=0;
    for(int i=0;i<len;++i){
        if(!bucket[i].empty()){
            bucket[i].sort();

            for(int k=0;k<bucket->size();++k){
                tmp[j++]=bucket[i].get(k);
            }
        }
    }
    //将temp中的数据写入原数组
    copy(tmp,tmp+len,arr);

    delete[] bucket;
}

// 找到num的从低到高的第pos位的数据
template <class T>
T GetDigitInPos(T num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}

//获取最大数得位数
template <class T>
int get_max_bit(T arr[],int len)
{
    T max=*max_element(arr,arr+len);
    int bit=0;
    while(max/=10){
        ++bit;
    }

    return bit+1;
}

//3、基数排序
template <class T>
void RadixSort(T arr[], int len)
{
    SingleList<T> *bucket=new SingleList<T>[10]();
    int K=get_max_bit(arr,len);
    T tmp[len]={};

    for(int k=0;k<K;++k){
        for(int i=0;i<len;++i){
            bucket[GetDigitInPos(arr[i],k)].insert(0,arr[i]);
        }

        int j=0;
        for(int i=0;i<10;++i){
            for(int k=0;k<bucket->size();++k){
                tmp[j++]=bucket[i].get(k);
            }
        }
    }

    copy(tmp,tmp+len,arr);

    delete[] bucket;
}


#endif //TESK_SORT_H
