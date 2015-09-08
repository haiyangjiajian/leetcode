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
    int astoint(char *s, int start, int end){
        char * tmp = new char[end -start + 1];
        memcpy(tmp, s+start, end - start);
        return atoi(tmp);
    }
    int expressionResult(char* s, int l) {
        int result = 0;
        if(s == NULL)
            return 0;
        int first = 0, second = 0, third = 0;
        char firstOp = '+', secondOp = '+';
        int i = 0;
        int start = 0;
        while(s[i]>'0' && s[i]<'9' && i < l){
            i++;
        }
        first  = astoint(s,start,i);
        firstOp = s[i];
        i = i+1;
        start = i;
        while(i < l && s[i]>'0' && s[i]< '9'){
            i++;
        }
        second = astoint(s,start,i);
        while (i < l) {
            secondOp = s[i];
            i++;
            start = i;
            while(s[i]>'0' && s[i]<'9'){
                i++;
            }
            third  = astoint(s,start,i);
            if(secondOp == '*'){
                second = second * third;
            }
            else if((secondOp == '+' || secondOp == '-') && firstOp == '*'){
                first = first * second;
                firstOp = secondOp;
                second = third;
            }
            else if((secondOp == '+' || secondOp == '-') && firstOp == '+'){
                first = first + second;
                firstOp = secondOp;
                second  = third;
            }
            else if((secondOp == '+' || secondOp == '-') && firstOp == '-'){
                first = first - second;
                firstOp = secondOp;
                second  = third;
            }
            else{
                cout<<"error"<<endl;
            }
        }
        if(firstOp == '+')
            result = first + second;
        else if(firstOp == '*')
            result = first * second;
        else
            result = first - second;
            
        return result;
    }
    void testVector(vector<int> a){
        a[0] = 1;
        a.push_back(1);
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    char s[]= "12+3+3*45-6";
//    cout<<solution.expressionResult(s,11)<<endl;
////    vector<int> a;
////    a.push_back(0);
////    solution.testVector(a);
////    cout<<a[0]<<"hello"<<a[1]<<endl;
//}


