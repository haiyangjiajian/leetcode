//
//  66PlusOne.cpp
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
    vector<int> plusOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }
    void add(vector<int>& digits, int num){
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            *it = (num + *it);
            num = *it/10;
            *it = *it%10;
        }
        if(num > 0)
            digits.insert(digits.begin(), num);
    }
};