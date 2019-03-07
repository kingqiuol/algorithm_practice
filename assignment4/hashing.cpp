//
// Created by jinqiu on 19-3-6.
//

#include "hashing.h"

int main()
{
    ListHash<string,int> lhash(10);
    lhash.insert(make_pair("jin",100));
    lhash.print();
    return 0;
}