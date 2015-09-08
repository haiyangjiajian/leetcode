//
//  7Atoi.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/29.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
            return 0;
        long long result = 0;
        int len = str.size();
        int i = 0;
        for(i = 0;i<len;i++){
            if(str[i]!= ' ')
                break;
        }
        int zhengfu = 1;
        if(str[i] == '-'){
            zhengfu = -1;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }
        if(i>=len)
            return 0;
        for(;i<len;i++){
            if(IsInt(str[i])){
                result = result*10 + str[i] - '0';
                if(zhengfu*result>0x7fffffff)
                     return 0x7fffffff;
                else if(zhengfu * result<0x7fffffff*-1)
                    return 0x80000000;
                    
            }
            else
                return zhengfu*result;
        }
    
        return zhengfu *result;
    }
    bool IsInt(char c){
        if(c>='0' && c<='9')
            return true;
        else
            return false;
    }
};
//int main(int argc, const char * argv[]) {
//    int a =0x80000000;
//    cout<<a;
//    if(1<0x80000000)
//        cout<<"hi"<<endl;
//    Solution solution;
//    cout<<solution.myAtoi("010");
//}

