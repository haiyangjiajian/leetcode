//
//  242ValidAnagram.cpp
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
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        vector<char> container(26,'1');
        for(int i = 0; i < s.length(); i++){
            container[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            container[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(container[i] != '1')
                return false;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution c;
    string s = "";
    if(c.isAnagram("a", "b"))
        cout<<"yes";
}