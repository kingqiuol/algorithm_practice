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

    cout<<"================>单向循环链表："<<endl;
    CycSingleList<int> CSlist;
    CSlist.insert(0,7);
    CSlist.insert(0,9);
    CSlist.insert(0,2);
    CSlist.insert(0,4);
    CSlist.print();
    ListNode<int> *p=CSlist.get_head();
    for(int i=0;i<CSlist.size();++i){
        p=p->next;
    }
    cout<<"==>"<<p->next->value_<<endl;
    cout<<"===>erase list 0:"<<endl;
    CSlist.erase(0);
    CSlist.print();
    cout<<"===>set list 0: 10"<<endl;
    CSlist.set(0,10);
    CSlist.print();
    cout<<"===>get list 3"<<endl;
    cout<<CSlist.get(2)<<endl;

    cout<<"================>双向链表："<<endl;
    DulList<int> dlist;
    dlist.dul_insert(0,1);
    dlist.push_back(3);
    dlist.push_front(2);
    dlist.push_back(11);
    dlist.dul_insert(1,9);
    dlist.print();

    dlist.pop_back();
    dlist.pop_front();
    dlist.dul_erase(0);
    dlist.print();

    dlist.dul_set(0,12);
    dlist.print();

    cout<<dlist.front()<<","<<dlist.back()<<","<<dlist.dul_get(0)<<endl;

    cout<<"================>双向循环链表："<<endl;
    CycDulList<int> cdlist;
    cdlist.insert(0,1);
    cdlist.push_back(3);
    cdlist.push_front(2);
    cdlist.push_back(11);
    cdlist.insert(1,9);
    cdlist.print();

    cdlist.pop_back();
    cdlist.pop_front();
    int v = cdlist.erase(0);
    cout<<"==>"<<v<<endl;
    cdlist.print();

    cdlist.set(0,12);
    cdlist.print();
    cout<<cdlist.front()<<","<<cdlist.back()<<","<<cdlist.get(0)<<endl;

    cout<<"================>静态链表："<<endl;
    StaticList<int> staticlist;
    staticlist.insert(1,2);
    staticlist.insert(1,3);
    staticlist.insert(1,8);
    staticlist.insert(1,1);
    staticlist.insert(1,0);
    staticlist.print();
    cout<<"================>"<<endl;
    staticlist.erase(3);
    staticlist.print();
    cout<<"================>"<<endl;
    staticlist.set(2,9999);
    cout<<"==>"<<staticlist.get(2)<<endl;
    cout<<"==>3 index :"<<staticlist.get_index(3)<<endl;
    staticlist.print();
    cout<<"================>"<<endl;
    staticlist.print_link();

    return 0;
}
