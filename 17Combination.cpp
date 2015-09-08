//
//  17Combination.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/8/23.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    
    vector<string>  letterCombinations(string input) {
        vector<string> result;
        result.push_back("");
        if(input.empty())
            return result;
        const vector<string> dict = {"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < input.length(); i++){
            if(input[i]<'0' || input[i] > '9')
                break;
            string candidate = dict[input[i] - '0'];
            vector<string> tmp;
            for(int j = 0; j < candidate.length() ;j++){
                for(int k = 0; k< result.size(); k++){
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }

        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> v = {0,1,2};
//    Solution solution;
//    cout<<solution.threeSumClosest(v,0);
//
//}
