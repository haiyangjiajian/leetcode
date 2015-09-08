//
//  LongestPalindrome.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/26.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2)
            return s;
        int start,left,right,maxLen = 1,maxLeft = 0;
        int len = s.size();
        for(start = 0;start<len && (len - start)>maxLen/2;){
            left = right = start;
            while(right<len -1 && s[right+1] == s[right])
                right++;
            start = right+1;
            while(right<len - 1 && left>0 && s[right+1] == s[left - 1]){
                right++;
                left--;
            }
            if( maxLen < right - left + 1){
                maxLen = right -left + 1;
                maxLeft = left;
            }
        }
        return s.substr(maxLeft,maxLen);
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    cout<<solution.longestPalindrome("aba");
//}