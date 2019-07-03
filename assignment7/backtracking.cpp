//
// Created by jinqiu on 19-5-14.
//

#include <iostream>

#include "backtracking.h"

using namespace std;

int main()
{
    double theProfit[]={9,10,7,4};
    double theWeight[]={3,5,2,1};
    int theNumberOfObjects=4;
    double theCapacity=7;
    cout<<knapsack(theProfit,theWeight,theNumberOfObjects,theCapacity)<<endl;

    return 0;
}
