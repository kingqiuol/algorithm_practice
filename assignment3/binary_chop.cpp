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
    int i=(end+start)/2;
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
int blur_binary_chop(int arr[],int len,int target)
{
    int start=0;
    int end=len-1;
    int mid=0;
    while(true){
        if(target<arr[start] || target>arr[end]){
            exit(0);
        }

        mid=(start+end)/2;

        if(arr[mid]>target){
            end=mid;
        }
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            start=mid;
        }
        if(end-start==1 && target<arr[end] && target>arr[start]){
            return end;
        }
    }
}

int main()
{
    int arr[5]={1,2,3,5,7};
    cout<<binary_search(arr,0,4,5)<<endl;
    cout<<blur_binary_chop(arr,5,4)<<endl;

    return 0;
}