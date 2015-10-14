//
//  Other_Silunbeixie.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/10/14.
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
    string s;
    cin>>s;
    string s1 = s;
    int a = s.find("bear");
    int lasta = 0;
    int b = s1.find("bear");
    int count = 0;
    int i = 0;
    while(a != -1){
        int x = s1.size() - (b + 4) + 1;//左边可取的部分
        int y = a + 1 - lasta;//右边可取的部分
        cout<<x<<" "<<y<<endl;
        count +=  x*y ;
        s1 = s1.substr(b+4);
        b = s1.find("bear");
        lasta = a + 1;
        a = s.find("bear", a+4);
        i++;
    }
    
    cout<<count<<endl;
}