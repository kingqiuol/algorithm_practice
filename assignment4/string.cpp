//
// Created by jinqiu on 2019/3/8.
//

#include "string.h"

#include <iostream>
#include <string>

using std::string;
using namespace std;


//�ַ���ƥ�������㷨
int AlmostBruteForce(string Text, string Pattern)
{
    int lenT = Text.length();
    int lenP = Pattern.length();

    int s,i;
    for (s = 0; s <= lenT-lenP; s++)

    {
        i = 0;
        bool bEqual = true;
        while (bEqual && (i < lenP))
        {
            if (Text[s+i] == Pattern[i]) {
                i++;
            } else {
                bEqual = false;
            }
        }

        if (bEqual) {
            return s;
        }
    }

    return -1;
}


int main()
{
    //BruteForce
    cout<<"============>BruteForce"<<endl;
    cout<<AlmostBruteForce("ABBBCGGBHJK","CGG")<<endl;

    //�ַ���ʵ��һ���ַ���,ֻ����a��z��26��Ӣ����ĸ��Trie��
    cout<<"============>TrieTree"<<endl;


    return 0;
}