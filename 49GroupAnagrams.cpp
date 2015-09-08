//
//  49GroupAnagrams.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/5.
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string> > group;
        for(auto i = strs.begin(); i != strs.end(); i++){
            string key = *i;
            sort(key.begin(), key.end());
            group[key].push_back(*i);
        }
        for(auto i = group.begin(); i != group.end(); i++){
            if(i->second.size() > 0){
                sort(i->second.begin(), i->second.end());
                result.insert(result.end(),i->second);
            }
        }
        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution c;
//    string s = "";
//    vector<string> v;
//    v.push_back(s);
//    c.groupAnagrams(v);
//}
//
//
