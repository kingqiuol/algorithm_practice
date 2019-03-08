//
// Created by jinqiu on 2019/3/8.
//

#ifndef TESK_LRU_H
#define TESK_LRU_H

#include "hashing.h"
#include "list.h"

#include <iostream>


using namespace std;


class LRUcache
{
public:
    LRUcache(size_t bucket_size,size_t capacity=50): bucket_size_(bucket_size),
                                                     capacity_(capacity),
                                                     size_(0),
                                                     hash_(bucket_size),
                                                     dul_list_(){}
    size_t size(){return size_;}
    size_t max_size(){return capacity_;}

    void put_cache(const pair<string,int> &thepair);
    void print();

private:
    ListHash<string,int> hash_;
    DulList<pair<string,int>*> dul_list_;
    size_t  size_;
    size_t bucket_size_;
    size_t capacity_;
};

void LRUcache::put_cache(const pair<string,int> &thepair)
{
    int index=hash_.search(thepair.first);
    if(-1==index){//��������ڸ�����
        //�����������
        if(size_>=capacity_){
            //��ȡ���һ�����ݵĵ�ַ������˫������͹�ϣ����ɾ��������
            pair<string,int> *back=dul_list_.dul_erase(size_-1);
            hash_.erase(back->first);
            --size_;
        }

        //���ϣ���в�������
        hash_.insert(thepair);

        //��ȡ���ݵ��׵�ַ
        pair<string,int> *tmp=hash_.find(thepair.first);

        //��˫�������в������ݵ��׵�ַ
        dul_list_.dul_insert(0,tmp);

        ++size_;
    }else{//����Ѵ��ڸ�����
        //���ظ����ݵ��׵�ַ
        pair<string,int> *tmp=hash_.find(thepair.first);

        //��˫�������л�ȡ�������׵�ַλ��
        int index=dul_list_.get_index(tmp);

        //ɾ���������׵�ַ
        dul_list_.dul_erase(index);

        //�������ͷ���������������׵�ַ
        dul_list_.dul_insert(0,tmp);

        //���ϣ���в�������
        hash_.insert(thepair);
    }
}

void LRUcache::print()
{
    hash_.print();

    for(int i=0;i<dul_list_.size();++i){
        pair<string,int> *temp=dul_list_.get_node(i)->value_;
        cout<<temp->first<<"->"<<temp->second<<",";
    }
    cout<<endl;
}

#endif //TESK_LRU_H
