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
    int len=ivec.size();
    int tmp=ivec[i];
    for(int k=i*2+1;k<len;k=k*2+1){
        if(k+1<len){
            if(flag && ivec[k]<ivec[k+1]){
                ++k;
            }
            if(!flag && ivec[k]>ivec[k+1]){
                ++k;
            }
        }


        if(flag && tmp<ivec[k]){
            ivec[i]=ivec[k];
            i=k;
        } else if(!flag && tmp>ivec[k]){
            ivec[i]=ivec[k];
            i=k;
        } else{
            break;
        }
    }
    ivec[i]=tmp;
}

//实现大顶堆
void max_top_stack(vector<int> &ivec)
{
    int len=ivec.size();
    for(int i=len/2-2;i>=0;--i){
        adjust_heap(ivec,i,MAX);
    }
}

//实现小顶堆
void min_top_stack(vector<int> &ivec)
{
    int len=ivec.size();
    for(int i=len/2-1;i>=0;--i){
        adjust_heap(ivec,i,MIN);
    }
}


int main()
{
    vector<int> vec{7,3,4,1,2,6,5,10,9,11};
    max_top_stack(vec);
    for(auto &c:vec){
        cout<<c<< " ";
    }
    cout<<endl;

    min_top_stack(vec);
    for(auto &c:vec){
        cout<<c<< " ";
    }
    cout<<endl;
    return 0;
}