//
// Created by jinqiu on 2020/9/15.
//

#ifndef TESK_DIVIDE_CONQUER_ALGORITHM_H
#define TESK_DIVIDE_CONQUER_ALGORITHM_H

/**
 * 一、基本思想
分治算法的主要思想是将原问题递归地分成若干个子问题，直到子问题满足边界条件，停止递归。将子问题逐个击破(一般是同种方法)，将已经解决的子问题合并，最后，算法会层层合并得到原问题的答案。

二、解题思路
分：递归地将问题分解为各个的子问题(性质相同的、相互独立的子问题)；
治：将这些规模更小的子问题逐个击破；
合：将已解决的子问题逐层合并，最终得出原问题的解；


分治法的设计思想是：将一个难以直接解决的大问题，分割成一些规模较小的相同问题，以便各个击破，分而治之。

分治法适用的情况：
原问题的计算复杂度随着问题的规模的增加而增加。
原问题能够被分解成更小的子问题。
子问题的结构和性质与原问题一样，并且相互独立，子问题之间不包含公共的子子问题。
原问题分解出的子问题的解可以合并为该问题的解。
 */


/*******************************************
*                数组中的逆序对            *
/*******************************************/
/*
 * 数组中的两个数，如果前面的一个大于后面的一个数字，则这两个数字组成逆序对。
 * 输入一个数组求数组中的逆序对的总数
 * */
int InversePairsCore(int *data,int *copy,int start,int end){
    if(start==end){
        copy[start]==data[start];
        return 0;
    }

    int length=(end-start)/2;

    int left=InversePairsCore(copy,data,start,start+length);
    int right=InversePairsCore(copy,data,start+length+1,end);

    int i=start+length;
    int j=end;

    int indexCopy=end;
    int count=0;
    while(i>=start && j>=start+length+1){
        if(data[i]>data[j]){
            copy[indexCopy--]=data[--i];
            count+=j-start-length;
        }else{
            copy[indexCopy--]=data[--j];
        }
    }

    for(;i>=start;--i){
        copy[indexCopy--]=data[i];
    }
    for(;j>=start+length+1;--j){
        copy[indexCopy--]=data[j];
    }

    return left+right+count;
}

int InversePairs(int *data,int length){
    if(data== nullptr||length<=0){
        return 0;
    }

    int *copy=new int[length];
    for(int i=0;i<length;++i){
        copy[i]=data[i];
    }

    int count=InversePairsCore(data,copy,0,length-1);
    delete[] copy;

    return count;
}


#endif //TESK_DIVIDE_CONQUER_ALGORITHM_H
