//
// Created by jinqiu on 19-3-5.
//

#include<iostream>

using namespace std;


/*
 * 实现一个有序数组的二分查找算法
 *
 * */
int binary_search(int arr[],int start,int end,int target)
{
    if(target>arr[end] || target<arr[start]){
        exit(0);
    }
    int i=(end-start)/2;
    if(arr[i]==target){
        return i;
    }else if(arr[i]>target){
        return binary_search(arr,start,i-1,target);
    }else{
        return binary_search(arr,i+1,end,target);
    }
}

/*
 * 实现模糊二分查找算法（比如大于等于给定值的第一个元素）
 * */


int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<binary_search(arr,0,4,1)<<endl;

    return 0;
}