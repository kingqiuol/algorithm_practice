//
// Created by jinqiu on 2020/9/15.
//

#ifndef TESK_DYNAMIC_PROGRAMMING_H
#define TESK_DYNAMIC_PROGRAMMING_H



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 动态规划就这么简单，就是穷举就完事了？我看到的动态规划问题都很难啊！

首先，动态规划的穷举有点特别，因为这类问题存在「重叠子问题」，如果暴力穷举的话效率会极其低下，所以需要【备忘录】或者【DP table】来优化穷举过程，避免不必要的计算。

而且，动态规划问题一定会具备「最优子结构」，才能通过子问题的最值得到原问题的最值。

另外，虽然动态规划的核心思想就是穷举求最值，但是问题可以千变万化，穷举所有可行解其实并不是一件容易的事，只有列出正确的「状态转移方程」才能正确地穷举。

以上提到的重叠子问题、最优子结构、状态转移方程就是动态规划三要素。具体什么意思等会会举例详解，但是在实际的算法问题中，写出状态转移方程是最困难的，这也就是为什么很多朋友觉得动态规划问题困难的原因，我来提供我研究出来的一个思维框架，辅助你思考状态转移方程：

明确「状态」
定义 dp 数组/函数的含义
明确「选择」
明确 base case
 */


/*******************************************
*        实现莱文斯坦最短编辑距离          *
/*******************************************/

int minDistance(string word1, string word2) {
    int m=word1.size(),n=word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;++i){
        dp[i][0]=i;
    }
    for(int j=1;j<=n;++j){
        dp[0][j]=j;
    }

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }

    return dp[m-1][n-1];
}



/*******************************************
*              最长递增子序列              *
/*******************************************/
int findLengthOfLCIS(vector<int>& nums) {
    vector<int> dp(nums.size(),1);

    for(int i=1;i<nums.size();++i){
        if(nums[i]>=nums[i-1]){
            dp[i]=dp[i-1]+1;
        }
    }

    return *max_element(dp.begin(),dp.end());
}


#endif //TESK_DYNAMIC_PROGRAMMING_H
