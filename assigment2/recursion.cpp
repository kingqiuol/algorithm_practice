//
// Created by jinqiu on 19-3-3.
//

#include <iostream>
#include <vector>
using namespace std;

//递归编程实践

//编程实现斐波那契数列
int fibonacci(const int &n)
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}

//编程实现求阶乘n!
size_t factorial(const size_t &n)
{
    if(n==1){
        return 1;
    }

    return n*factorial(n-1);
}

//编程实现一组数据集合的全排列
void full_permutation(int a[], int k, int m){
    if( k == m ){
        for(int i = 0; i <= m; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    else{
        for(int j = k; j <= m; j++){
            swap(a[k],a[j]);
            full_permutation(a,k+1,m);
            swap(a[k],a[j]);
        }
    }
}


int main()
{
    //斐波那契数列
    cout<<fibonacci(5)<<endl;

    //阶乘n!
    cout<<factorial(19)<<endl;

    //全排列
    int a[4] = {1,2,3,4}; //对数组中的1,2,3,4进行全排列
    full_permutation(a,0,3);

    return 0;
}