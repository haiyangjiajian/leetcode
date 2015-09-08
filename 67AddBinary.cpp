
//
//  67AddBinary.cpp
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
    string addBinary(string a, string b) {
        if(a.length() == 0)
            return b;
        if(b.length() == 0)
            return a;
        string res(max(a.length(),b.length()) + 1, '0');
        int k = res.size() - 1;
        int carry = 0;
        int i,j;
        for(i = a.length() - 1, j = b.length() - 1; i>=0 && j>=0; i-- ,j--){
            int tmp = a[i] - '0'+ b[j] - '0' + carry ;
            carry = tmp/2;
            res[k] = tmp%2 + '0';
            k--;
        }
        if(i < 0){
            while(j>=0){
                int tmp = b[j] - '0' + carry ;
                carry = tmp/2;
                res[k] = tmp%2 + '0';
                k--;
                j--;
            }
        }
        else if(j < 0){
            while(i>=0){
                int tmp = a[i] - '0' + carry ;
                carry = tmp/2;
                res[k] = tmp%2 + '0';
                k--;
                i--;
            }
        }
        if (carry > 0) {
            res[k] = carry + '0';
        }
        int index = res.find_first_not_of("0");
        if(index != -1)
            return res.substr(index);
        return "0";
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    string s1 = "1010";
//    string s2 = "1011";
//    cout<<c.addBinary(s1, s2)<<endl;
//    char b[10] = "hello";
//    char d[10];
//    
//    
//    const int i = 0;
//    int *j = (int *)&i;
//    *j = 1;
//    cout<<&i<<"  "<<j<<endl;
//    printf("%d,%d\n", i, *j);
//    cout<<&i<<"  "<<j<<endl;
//
//}




