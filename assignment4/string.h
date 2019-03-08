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
    int terminableSize;          //存储以此结点为结尾的字串的个数
    int nodeSize;                //记录此结点孩子的个数
    trieNode* children[Size];    //该数组记录指向孩子的指针
};

class TrieTree
{
public:
private:
};

#endif //TESK_STRING_H
