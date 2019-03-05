//
// Created by jinqiu on 19-3-3.
//

#ifndef TESK_SORT_H
#define TESK_SORT_H

#include <iostream>

using namespace std;

/*******************************************
*                  ��������                 *
*******************************************/
//1��ð������
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

//2����������
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
*                  ��������                 *
*******************************************/
//1����������
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

//2��ϣ������
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
*                  ѡ������                 *
*******************************************/
//1��ѡ������
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

//2��������
//�����󶥶ѣ����ǵ������̣������ڴ󶥶��ѹ����Ļ����ϣ�
template <class T>
void adjust_heap(T arr[], int i, int len)
{
    int temp = arr[i];//ȡ����ǰԪ��
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1){//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
        if (k + 1 < len && arr[k] < arr[k + 1]){//������ӽ��С�����ӽ�㣬kָ�����ӽ��
            ++k;
        }
        if (arr[k] > temp){//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н���)
            arr[i] = arr[k];
            i = k;
        }
        else{
            break;
        }
    }
    arr[i] = temp;//��tempֵ�ŵ����յ�λ��
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
    //1����������
    for (int i = len/2 - 1; i >= 0; i--){
        //�ӵ�һ����Ҷ�ӽڵ�������£������������
        adjust_heap(arr, i, len);
    }

    //2�������ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
    for(int j=len-1;j>0;--j){
        swap(arr,0,j);
        adjust_heap(arr,0,j);
    }
}

/*******************************************
*                  �鲢����                 *
*******************************************/
//1���鲢����
template <class T>
void MergeSort(T arr[],int len)
{

}

/*******************************************
*           ����ʱ��ǱȽ�������              *
*******************************************/
//1����������
template <class T>
void CountingSort(T arr[],int len)
{

}

//2��Ͱ����
template <class T>
void BucketSort(T arr[],int len)
{

}

//3����������
template <class T>
void RadixSort(T arr[],int len)
{

}


#endif //TESK_SORT_H
