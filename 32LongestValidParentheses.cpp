//
//  32LongestValidParentheses.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/13.
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
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        stack<int> left;
        int maxLen = 0;
        int last = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] ==  '(')
                left.push(i);
            else{
                if(left.empty()){
                    last = i;
                }
                else{
                    left.pop();
                    if(left.empty()){
                        maxLen = max(maxLen, i - last);
                    }
                    else{
                        maxLen = max(maxLen, i - left.top());
                    }
                }
            }
        }
        return maxLen;
    }
};
