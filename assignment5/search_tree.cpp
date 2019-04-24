//
// Created by jinqiu on 19-4-21.
//
#include <iostream>
#include <vector>
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

    return 0;
}