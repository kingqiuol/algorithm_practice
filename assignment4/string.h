//
// Created by jinqiu on 2019/3/8.
//

#ifndef TESK_STRING_H
#define TESK_STRING_H

class trieNode
{
public:
    trieNode() : terminableSize(0), nodeSize(0) { for(int i = 0; i < Size; ++i) children[i] = NULL; }
    ~trieNode()
    {
        for(int i = 0; i < Size; ++i)
        {
            delete children[i];
            children[i] = NULL;
        }
    }
public:
    int terminableSize;          //�洢�Դ˽��Ϊ��β���ִ��ĸ���
    int nodeSize;                //��¼�˽�㺢�ӵĸ���
    trieNode* children[Size];    //�������¼ָ���ӵ�ָ��
};

class TrieTree
{
public:
private:
};

#endif //TESK_STRING_H
