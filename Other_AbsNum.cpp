//
//  Other_AbsNum.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/1.
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
    int absNumSameOp(int *a, int length, int lastResult){
        int result = 0;
        int lastNumber = 0x80000000;
        if(a[0] < 0)
            lastResult = lastResult * -1;
        cout<<a[0]<<"   "<<length<<endl;
        cout<<lastResult<<":lastResult"<<endl;
        for(int i = 0;i<length; i++){
            if(a[i] == lastNumber && a[i]!=lastResult){
                result++;
                lastResult = a[i];
            }
            else{
                lastNumber = a[i];
            }
        }
        return result;
    }
    int absNum(int * a, int length){
        if(a == nullptr || length <= 0)
            return 0;
        int result = 0;
        int l = 0, r = length -1;
        int lastNumber = 0x80000000, lastResult = 0x80000000;
        while(l < r && a[l] < 0 && a[r] > 0){
            if(abs(a[l]) < a[r] && l < r){
                if(a[r] == lastNumber && a[r]!= lastResult){
                    result++;
                    lastResult = a[r];
                    r--;
                }
                else{
                    lastNumber = a[r];
                    r--;
                }
                    
            }
            else if(abs(a[l])>a[r] && l < r){
                if(a[l] == lastNumber && a[l]!= lastResult){
                    result++;
                    lastResult = abs(a[l]);
                    l++;
                }
                else{
                    lastNumber = abs(a[l]);
                    l++;
                }
            }
            else if(l < r && abs(a[l]) == a[r] && a[l] != lastResult){
                lastResult = a[r];
                result++;
                l++;
                r--;
            }
        }
        cout<<result<<endl;
        result += absNumSameOp(a+l,r-l+1,lastResult);
        
        return result;
    }
    
    int sameOp(int *a,const int l){
        int count = 0;
        cout<<a[0]<<"   "<<l<<endl;
        int last  = a[0];
        for(int i =1 ;i<l;i++){
            if(a[i] == last){
                count++;
            }
            else
                last = a[i];
        }
        return l - count;
    }
    int sameOpWithLast(int *a,const int l, int last){
        if(a == nullptr || l <= 0)
            return 0;
        if(a[0] < 0)
            last = -1 * last;
        int count = 0;
        for(int i =0 ;i < l;i++){
            if(a[i] == last){
                count++;
            }
            else
                last = a[i];
        }
        return l - count;
    }
    
    int diffOp(int *a,const int length){
        if(a == nullptr || length <= 0)
            return 0;
        int count = 0;
        int last = -1;
        int l = 0, r = length -1;
        while(l < r && a[l] < 0 && a[r] > 0){
            if(abs(a[l]) < a[r]){
                if(a[r] != last){
                    count++;
                    last = a[r];
                }
                r--;
            }
            else if(abs(a[l]) == a[r]){
                if(a[r] != last){
                    count ++;
                    last = a[r];
                }
                r--;
                l++;
            }
            else if(abs(a[l]) > a[r]){
                count++;
                while(l+1<r && a[l] < 0 && a[l+1] == a[l]){
                    l++;
                }
                l++;
            }
        }
        cout<<count<<endl;
        count += sameOpWithLast(a+l, r- l,last );
        return count;
    }
    int absoluteNum(int *a, const int l){
        if(a == nullptr || l == 0)
            return 0;
        if(a[0] < 0 && a[l-1] > 0){
            return diffOp(a, l);
        }
        else
            return sameOp(a,l);
            
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    int s[]= {-6,-6,-6,-1,-1,-1,-1,-1,-1, 0,0,1,2,2,2, 2, 5,7};
////    cout<<sizeof(s)/sizeof(int)<<endl;
////    cout<<solution.absNum(s,sizeof(s)/sizeof(int))<<endl;
//    cout<<solution.absoluteNum(s, sizeof(s)/sizeof(int))<<endl;
//    return 0;
//}


