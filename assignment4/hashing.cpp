//
// Created by jinqiu on 19-3-6.
//

#include "hashing.h"

int main()
{
    cout<<"=========>ListHash:"<<endl;
    ListHash<string,int> lhash(10);
    lhash.insert(make_pair("jin",100));
    lhash.insert(make_pair("qiu",200));
    lhash.insert(make_pair("kin",300));
    lhash.insert(make_pair("ol",400));
    lhash.print();
    cout<<"size:"<<lhash.size()<<endl;
    cout<<"========"<<endl;
    pair<string,int> result=lhash.erase("ol");
    lhash.print();
    cout<<"========"<<endl;
    lhash.set("jin",250);
    lhash.print();
    cout<<"========"<<endl;
    pair<string,int> l1=lhash.find("jin");
    cout<<"pair:"<<l1.first<<"->"<<l1.second<<endl;
    cout<<"qiu index:"<<lhash.search("qiu");
    return 0;
}