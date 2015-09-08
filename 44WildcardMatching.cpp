//
//  44WildcardMatching.cpp
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
    bool isMatch(string s, string p) {
        return matchCore3(s.c_str(),p.c_str());
    }
    bool matchCore(const char* s, const char* p){
        if(*s == '\0' && *p == '\0')
            return true;
        if(*s != '\0' && *p == '\0')
            return false;
        if(*(p + 1) == '*'){
            if(*s == *p || (*p == '?' && *s != '\0')){
                return matchCore(s + 1, p + 2)||
                matchCore(s,p + 2)||
                matchCore(s + 1, p);
            }
            else
                return matchCore(s, p + 2);
                
        }
        if(*s == *p || (*p == '?' && *s != '\0'))
            return matchCore(s + 1, p + 1);
        return false;
    }
    bool matchCore2(const char* s, const char* p){
        if(*s == '\0' && *p == '\0')
            return true;
        if(*s != '\0' && *p == '\0')
            return false;
       // cout<<s<<"  "<<p<<endl;
        if(*p == '*'){
            if(*s == '\0')
                return matchCore2(s,p + 1);
            else{
                return matchCore2(s + 1, p + 1)||
                matchCore2(s,p + 1)||
                matchCore2(s + 1, p);
            }
            
        }
        if(*s == *p || (*p == '?' && *s != '\0'))
            return matchCore2(s + 1, p + 1);
        return false;
    }
    bool isMatch2(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else
                return false;
        }
        while (j < n && p[j] == '*')
            j++;
        return j == n;
    }
    bool matchCore3(const char *s, const char *p){
        const char *star = NULL;
        const char *ss = s;
        while(*s != '\0'){
            if(*p == '?' || *p == *s){
                p++;
                s++;
                continue;
            }
            if(*p == '*'){
                star = p;
                p++;
                ss = s;
                continue;
            }
            if(star){
                p = star + 1;
                s = ++ss;
                continue;
            }
            return false;
        }
        while(*p == '*')
            p++;
        return !*p;
    }
    
    
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    string s1 = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
//    string s2 = "*";
//    if(c.isMatch2(s1, s2)){
//        cout<<"yes"<<endl;
//    }
//    else{
//        cout<<"no"<<endl;
//    }
//}
//
