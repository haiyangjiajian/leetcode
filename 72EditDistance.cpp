//
//  72EditDistance.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/19.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int f[n + 1][m + 1];
        for(int i = 0;i<= n;i++){
            f[i][0] = i;
        }
        for(int j = 0; j <= m; j++){
            f[0][j] = j;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else{
                    int mn = 1 + min(f[i - 1][j], f[i][j - 1]);
                    f[i][j] = min(mn, 1 + f[i - 1][j - 1]);
                }
            }
        }
        return f[n][m];
        
    }
};
