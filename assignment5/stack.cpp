//
// Created by jinqiu on 19-3-2.
//
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1
#define MIN 0

void adjust_heap(vector<int> &ivec,int &i,int flag)
{

}

//实现大顶堆
void max_top_stack(vector<int> &ivec)
{
    int len=ivec.size();
    for(int i=len/2-1;i>=0;--i){
        adjust_heap(ivec,i,MAX);
    }
}

int main()
{


    return 0;
}