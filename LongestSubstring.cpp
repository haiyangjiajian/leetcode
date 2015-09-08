//
//  LongestSubstring.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/26.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int maxLength = 0;
        int exist[256] = {false};
        int i  = 0;
        int j = 0;
        while(j<length){
            if(exist[s[j]]){
                maxLength = max(maxLength,j - i);
                while(s[i]!=s[j]){
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }
            else{
                exist[s[j]] = true;
                j++;
            }
        }
        maxLength = max(maxLength,j -i);
        return  maxLength;
    }
    int max(int i,int j){
        return i>j?i:j;
    }
};


