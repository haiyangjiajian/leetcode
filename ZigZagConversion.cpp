//
//  ZigZagConversion.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/26.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        char* a = new char[n+1];
        int k=0;
        if(numRows==1 || n<=numRows)return s;
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<n;j+=2*(numRows-1))
            {
                a[k++]=s[j];
                if(i!=0 && i!=numRows-1)
                {
                    int t=j+2*(numRows-1)-2*i;
                    if(t<n)
                        a[k++]=s[t];
                }
            }
        }
        a[k]='\0';
        string result(a);
        return result;
    }


};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    cout<<solution.convert("PAYPALISHIRING",3);
//}
