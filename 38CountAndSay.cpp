//
//  38CountAndSay.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/4.
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
    string countAndSay(int n) {
        string s("1");
        for(int i = 1; i < n; i++)
            s = getNext(s);
        return s;
    }
    string getNext(const string &s){
        stringstream ss;
        char last = s[0];
        int count = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == last)
                count++;
            else{
                ss<<count<<last;
                count = 1;
                last = s[i];
            }
        }
        ss<<count<<last;
        return ss.str();
    }
};
