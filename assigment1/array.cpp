//
// Created by jinqiu on 19-2-26.
//
#include "array.h"

template <class T>
void add_sort_array(OrderedArray<T> &a1,OrderedArray<T> &a2,OrderedArray<T> &out)
{
    out.max_size()=a1.max_size()+a2.max_size();
    out.size()=a1.size()+a2.size();
    out.expend_capacity();
    copy(a1.get(),a1.get()+a1.size(), out.get());
    copy(a2.get(),a2.get()+a2.size(), out.get()+a1.size());
    sort(out.get(),out.get()+out.size(), [](const T &a,const T &b){return a<b;});
}

int main()
{
    Array<int> array1;
    cout<<array1.max_size()<<endl;
    array1.insert(0,1);
    array1.insert(0,2);
    array1.insert(0,3);
    array1.print();
    array1.erase(1);

    cout<< array1.size()<<endl;
    cout<<array1.get(0)<<endl;
    array1.print();

    OrderedArray<int> oder_array1;
    cout<<oder_array1.max_size()<<endl;
    oder_array1.ordered_insert(1);
    oder_array1.ordered_insert(9);
    oder_array1.ordered_insert(5);
    oder_array1.print();
    OrderedArray<int> oder_array2;
    oder_array2.ordered_insert(6);
    oder_array2.ordered_insert(2);
    oder_array2.ordered_insert(7);
    oder_array2.print();
    //合并两个顺序数组
    OrderedArray<int> oder_array3;
    add_sort_array(oder_array1,oder_array2,oder_array3);
    oder_array3.print();

    return 0;
}