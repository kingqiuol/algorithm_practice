//
// Created by jinqiu on 19-2-27.
//
#include "list.h"

template <class T>
void add_ordered_list(SingleList<T> &list1,SingleList<T> &list2,SingleList<T> &out)
{
    ListNode<T> *l1=list1.get_head();
    ListNode<T> *l2=list2.get_head();

    int i=0;
    while(l1!= nullptr){
        if(l1->value_<l2->value_){
            out.insert(0,l1->value_);
            l1=l1->next;
            ++i;
        } else if(l1->value_>l2->value_){
            out.insert(i,l2->value_);
            l2=l2->next;
            ++i;
        } else{
            out.insert(i,l1->value_);
            ++i;
            out.insert(i,l2->value_);
            ++i;
            l1=l1->next;
            l2=l2->next;
        }

        if(l2== nullptr){
            break;
        }

    }

    if(l1){
        out.insert(i,l1->value_);
    } else{
        out.insert(i,l2->value_);
    }
}

int main()
{
    //单向链表测试
    cout<<"================>单向链表："<<endl;
    SingleList<int> list1;
    list1.insert(0,1);
    list1.insert(0,3);
    list1.insert(1,2);
    list1.insert(2,7);
    list1.print();
    //list1.erase(1);
    //list1.print();
    cout<<"get(0):"<<list1.get(0)<<endl;
    list1.set(0,10);
    list1.print();
    list1.reverse();
    list1.print();
    cout<<"===>list1:";
    list1.sort();
    list1.print();
    ListNode<int> *node=list1.get_mid_node();
    cout<<node->value_<<endl;

    SingleList<int> list2;
    list2.insert(0,7);
    list2.insert(0,9);
    list2.insert(0,2);
    list2.insert(0,4);
    list2.print();
    list2.sort();
    cout<<"===>list2:";
    list2.print();
    cout<<"===>list1+list2:";
    SingleList<int> list3;
    add_ordered_list(list1,list2,list3);
    list3.print();


    return 0;
}
