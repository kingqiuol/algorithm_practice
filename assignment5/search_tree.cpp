//
// Created by jinqiu on 19-4-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "search.h"

using namespace std;

int main()
{
    vector<pair<int,int>> a,b;

    b.push_back(make_pair(0,1));
    b.push_back(make_pair(1,2));

    for(auto c:b){
        cout<<c.first<<" "<<c.second<<endl;
    }

    vector<pair<int,int>> c(a.begin(),a.end());
    sort(c.begin(),c.end(),[](pair<int,int> a,pair<int,int> b){return a.first<b.first;});

    return 0;
}