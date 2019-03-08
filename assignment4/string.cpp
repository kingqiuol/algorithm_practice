//
// Created by jinqiu on 2019/3/8.
//

#include "string.h"

#include <iostream>
#include <string>

using std::string;
using namespace std;


//字符串匹配朴素算法
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

    //字符串实现一个字符集,只包含a～z这26个英文字母的Trie树
    cout<<"============>TrieTree"<<endl;


    return 0;
}