//
// Created by jinqiu on 19-3-3.
//
#include "sort.h"

#include <time.h>
#include <vector>
#include <deque>

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

/**
*给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
*你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。返回滑动窗口最大值。
*示例:
*输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
*输出: [3,3,5,5,6,7]
**/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    if(n == 0 || k > n)
        return ans;
    deque<int> que;
    for(int i = 0; i < n; i ++)
    {
        if(!que.empty())
        {
            if(i >= que.front()+k)
                que.pop_front();
            while(!que.empty() && nums[i] >= nums[que.back()])
                que.pop_back();
        }
        que.push_back(i);
        if(i + 1 >= k)
            ans.push_back(nums[que.front()]);
    }
    return ans;
}

/*
 * 编程实现 O(n) 时间复杂度内找到一组数据的第 K 大元素
 *
 * */
int quick_sort(int arr[],int start,int end,int K)
{
    int temp=arr[end];
    int i=start;
    int j=end;
    while(i<j){
        while(i<j&&arr[i]<temp){
            ++i;
        }
        if(i<j){
            arr[j]=arr[i];
            --j;
        }
        while(i<j&&arr[j]>temp){
            --j;
        }
        if(i<j){
            arr[i]=arr[j];
            ++i;
        }
    }
    arr[i]=temp;

    if(i==K){
        return i;
    } else if(i<K){
        return quick_sort(arr,i+1,end,K);
    } else{
        return quick_sort(arr,start,i-1,K);
    }

}

int find_k_max(int arr[],int len,int k)
{
    int start=0;
    int end=len-1;
    return quick_sort(arr,start,end,len-k);
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

//    c_start=clock();
//    cout<<"SelectSort:";
//    ShellSort<int>(arr,100000);
//    print(arr,100);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

//    c_start=clock();
//    cout<<"HeapSort:";
//    ShellSort<int>(arr,100000);
//    print(arr,100);
//    c_end=clock();
//    cout<<c_end-c_start<<" ms"<<endl;

//    vector<int> num={1,3,-1,-3,5,3,6,7};
//    vector<int> result=maxSlidingWindow(num,3);
//    for(auto &c:result){
//        cout<<c<<" ";
//    }
//    cout<<endl;

    int arr1[10]={9,26,11,13,8,15,5,21,10,14};
    cout<<arr1[find_k_max(arr1,10,3)]<<endl;

    return 0;
}
