//
// Created by jinqiu on 2020/9/15.
//

#include <iostream>
#include <string>
#include "dynamic_programming.h"

using namespace std;


int main(){

    //最短编辑距离
    string s1="hello";
    string s2="hegnbvxdsdb";
    cout<<minDistance(s1,s2)<<endl;

    return 0;
}
