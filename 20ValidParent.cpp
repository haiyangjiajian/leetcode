//
//  20ValidParent.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/8/23.
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
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        unordered_map<char, char> dict;
        dict.insert(make_pair('(', ')'));
        dict.insert(make_pair('{', '}'));
        dict.insert(make_pair('[', ']'));
        stack<char> match;
        for(int i = 0; i < s.length(); i++){
            
        }
        return true;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    if(solution.isValid("(abc{})")){
//        cout<<"yes"<<endl;
//    }
//}


