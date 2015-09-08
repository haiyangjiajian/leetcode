//
//  28StrStr.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/2.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int alen = haystack.length();
        int blen = needle.length();
        if(alen < blen)
            return -1;
        if(alen == 0|| blen == 0)
            return 0;
        for(int i = 0; i <= alen -blen; i++){
            int j = 0;
            for(j = 0 ;j< blen ;j++){
                if(!(haystack[i+j] == needle[j]))
                    break;
            }
            if(j == blen)
                return i;
        }
        return -1;
    }
    vector<int> getNext(string s){
        vector<int> next;
        next.push_back(-1);
        int k = -1;
        int j = 0;
        while(j < s.length() - 1){
            if(k == -1 || s[k] == s[j]){
                k++;
                j++;
                if(s[j] != s[k])
                    next.push_back(k);
                else
                    next.push_back(next[k]);
            }
            else{
                k = next[k];
            }
        }
        return next;
    }
    int strStrKmp(string haystack, string needle){
        int alen = haystack.length();
        int blen = needle.length();
        if(alen < blen)
            return -1;
        if(alen == 0|| blen == 0)
            return 0;
        int i = 0, j = 0;
        vector<int> next = getNext(needle);
        while(i < alen && j < blen){
            if(j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
            
        }
        if(j == blen)
            return i- j;
        else
            return -1;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution c;
//    cout<<c.strStrKmp("mississippi", "issippi")<<endl;
//}

