//
//  Other_Linkedin.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/10/10.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, const char * argv[])
{
    int a, b;
    cin>>a>>b;
    int a1 = a;
    map<int,int> r;
    int count = 0;
    int max = 0;
    while(a>0){
        int t, n;
        cin>>t>>n;
        map<int,int>::iterator it = r.find(t);
        if(it == r.end())
            r.insert(make_pair(t, n));
        else
            it -> second += n;
        if(t >max)
            max = t;
        a--;
    }
    int i = 1;
    int j = 0;
    while(j < a1){
        map<int,int>::iterator it = r.find(i-1);
        int av = b;
        if(it != r.end()){
        if(it->second > b){
            it->second -= b;
            count += b;
            i++;
            continue;
            
        }
        else if(it->second == b){
            count += b;
            it->second = 0;
            j++;
            i++;
            continue;
        }
        else{
            count += it ->second;
            av = b - it->second;
            it->second = 0;
            j++;
        }
        }
        map<int,int>::iterator it2 = r.find(i);
        if(it2 != r.end()){
            if(it2->second > av){
                it2->second -= av;
                count += av;
            }
            else if(it2->second == av){
                count += av;
                it2->second = 0;
                j++;
            }
            else{
                count += it2 ->second;
                it2->second = 0;
                j++;
            }
        }
        i++;
        if(i> max +1)
            break;
        
    }
    cout<<count<<endl;
}
