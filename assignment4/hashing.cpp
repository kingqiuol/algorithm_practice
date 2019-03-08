//
// Created by jinqiu on 19-3-6.
//

#include "hashing.h"



int main()
{
    cout<<"=========>ArrayHash:"<<endl;
    ArrayHash<string,int> ahash(5);
    ahash.insert(make_pair("jin",100));
    ahash.insert(make_pair("qiu",200));
    ahash.insert(make_pair("kin",300));
    ahash.insert(make_pair("ol",400));
    ahash.print();
    cout<<"size:"<<ahash.size()<<endl;
    cout<<"========"<<endl;
    ahash.erase("kin");
    ahash.print();
    ahash.set("jin",250);
    ahash.print();
    cout<<"========"<<endl;
    pair<string,int> *l2=ahash.find("ol");
    if(l2!=NULL){
        cout<<"pair:"<<l2->first<<"->"<<l2->second<<endl;
    }else{
        cout<<"don't find"<<endl;
    };

    cout<<"qiu index:"<<ahash.search("qiu")<<endl;

    cout<<"=========>ListHash:"<<endl;
    ListHash<string,int> lhash(5);
    lhash.insert(make_pair("jin",100));
    lhash.insert(make_pair("qiu",200));
    lhash.insert(make_pair("kin",300));
    lhash.insert(make_pair("ol",400));
//    lhash.insert(make_pair("zhi",500));
//    lhash.insert(make_pair("wang",600));

    lhash.print();
    cout<<"size:"<<lhash.size()<<endl;
    cout<<"========"<<endl;
    lhash.erase("ol");
    lhash.print();
    cout<<"========"<<endl;
    lhash.set("jin",250);
    lhash.print();
    cout<<"========"<<endl;
    pair<string,int> l1=lhash.find("jin");
    cout<<"pair:"<<l1.first<<"->"<<l1.second<<endl;
    cout<<"qiu index:"<<lhash.search("qiu")<<endl;
    return 0;
}