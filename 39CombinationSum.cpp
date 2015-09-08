//
//  39CombinationSum.cpp
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size() == 0 || target < 0)
            return result;
        vector<int> perm;
        sort(candidates.begin(), candidates.end());
        
        combinationSumHelper(candidates, perm, target, result, 0);
        return result;
    }
    void combinationSumHelper(vector<int>& candidates, vector<int> perm, int target,vector<vector<int>>& result, int start){
        if(target < 0)
            return ;
        else if(target == 0){
            result.push_back(perm);
            return;
        }
        else{
            for(int i = start; i < candidates.size(); i++){
                perm.push_back(candidates[i]);
                combinationSumHelper(candidates, perm, target - candidates[i], result, i);
                perm.pop_back();
            }
        }
    }
};
