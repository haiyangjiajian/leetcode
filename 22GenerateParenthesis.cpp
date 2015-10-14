//
//  22GenerateParenthesis.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/9.
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
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        generateCore(0,2*n,0,result,s);
        
        return result;
    }
    void generateCore(int i, int n, int open, vector<string> & result, string s){
        if(open < 0)
            return;
        if(i == n){
            if(open == 0)
                result.push_back(s);
            return;
        }
        generateCore(i + 1, n, open + 1, result, s + "(");
        generateCore(i + 1, n, open - 1, result, s + ")");
    }
    void test(string &s){
        s += "a";
    }
};

//int main(int argc, const char * argv[]) {
//    vector <string> v;
//    for(int i=0; i<1000000; i++)
//        v.push_back("abcdefghijklmn");
//    cout << "Vector 的 容量为" << v.capacity() << endl;
//    vector<string>(v).swap(v);
//    
//    cout << "Vector 的 容量为" << v.capacity() << endl;
//    
//       Solution c;
//    c.generateParenthesis(2);
//   }