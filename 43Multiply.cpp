//
//  43Multiply.cpp
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
    string multiply(string num1, string num2) {
        if(num1.length() == 0 || num2.length() == 0)
            return "";
        string res(num1.length() + num2.length(),'0');
        
        for(int i = num1.length() - 1; i >= 0; --i){
            int carry = 0;
            for(int j = num2.length() - 1; j >= 0; --j){
                int tmp = res[i + j +1] - '0' + (num1[i] - '0')*(num2[j] - '0') + carry;
                res[i + j + 1] = tmp%10 + '0';
                carry = tmp/10;
            }
            res[i] += carry;
        }
        int index = res.find_first_not_of("0");
        if(index != -1){
            return res.substr(index);
        }
        return "0";
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    string s1 = "9";
//    string s2 = "9";
//    c.multiply(s1, s2);
//
//}

