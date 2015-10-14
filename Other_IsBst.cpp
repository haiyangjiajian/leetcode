//
//  Other_IsBst.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/14.
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
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(sequence.size() == 0)
    		return false;
    	return VerifyCore(sequence, 0, sequence.size() - 1);
    }
    bool VerifyCore(vector<int> sequence, int start, int end){
    	if(start >= end)
    		return true;
    	int root = sequence[end];
    	int i = 0;
    	for(i = 0; i < end; i++){
    		if(sequence[i] > root)
    			break;
    	}
    	int middle = i;
    	for(;i < end; i++){
    		if(sequence[i] < root)
    			return false;
    	}
    	return VerifyCore(sequence, start, middle -1) && VerifyCore(sequence, middle, end - 1);
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    vector<int> a;
//    a.push_back(1);
//    a.push_back(4);
//    a.push_back(2);
//    a.push_back(3);
//    if(c.VerifySquenceOfBST(a))
//        cout<<"yes"<<endl;
//    else
//        cout<<"no"<<endl;
//}

