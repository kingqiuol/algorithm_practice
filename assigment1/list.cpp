//
// Created by jinqiu on 19-2-27.
//

#include "list.h"

template <class T>
void add_ordered_list(SingleList<T> &list1,SingleList<T> &list2,SingleList<T> &out)
{
    ListNode<T> *l1=list1.get_head();
    ListNode<T> *l2=list2.get_head();
    ListNode<T> *l3=out.get_head();

    while(l1!= nullptr){
        cout<<l1->value_<<","<<l2->value_<<endl;

        if(l1->value_<l2->value_){
            if(l3== nullptr){
                l3=l1;
            } else{
                l3->next=l1;
                l3=l3->next;
            }

            l1=l1->next;
        } else if(l1->value_>l2->value_){
            if(l3== nullptr){
                l3=l2;
            } else{
                l3->next=l2;
                l3=l3->next;
            }
            l2=l2->next;
        } else{
            if(l3== nullptr){
                l3=l1;
                l1=l1->next;
                l3->next=l2;
                l3=l3->next;
                l2=l2->next;
            } else{
                l3->next=l1;
                l3=l3->next;
                l1=l1->next;
                l3->next=l2;
                l3=l3->next;
                l2=l2->next;
            }
        }
        cout<<"l3:"<<l3->value_<<endl;
        if(l2== nullptr){
            break;
        }


    }

    if(l1){
        l3->next=l1;
    } else{
        l3->next=l2;
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
    cout<<"两个顺序链表合并：";
    SingleList<int> list3;
    add_ordered_list(list1,list2,list3);
    list3.print();


    return 0;
}

