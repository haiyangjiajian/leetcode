//
//  58LengthOfLastWord.cpp
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
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int i = s.size() -1;
        int length = 0;
        while(i >= 0 && s[i] == ' ')
            i--;
        while(i >= 0 && s[i] != ' '){
            i--;
            length++;
        }
        return length;

    }
};
