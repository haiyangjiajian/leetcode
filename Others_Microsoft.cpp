//
//  Others_Microsoft.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/29.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
#include<cmath>
#include <string>
#include<sstream>
using namespace std;
struct P{
    int x;
    int y;
    P(int x1, int y1):x(x1), y(y1){}
    
};
bool comp(const P &a,const P &b){
    if(a.x > b.x)
        return true;
    else if(a.x == b.x){
        if(a.y > b.y)
            return true;
        else
            return false;
    }
    else
        return false;
    
}
//int main(int argc, const char * argv[]){
//    float a,b,c;
//    vector<P> result;
//    float max = 0;
//    while(cin >> a >> b >>c) {
//        for(int i = ceil(a-c); i <= floor(a+c); i++){
//            for(int j = ceil(b - c); j <= floor(b + c); j++){
//                int dis = (i-a)*(i-a) + (j-b)*(j-b);
//                if(dis <= floor(c * c)){
//                    if(dis == max){
//                        P p(i,j);
//                        result.push_back(p);
//                    }
//                    else if(dis > max){
//                        vector<P> t;
//                        P p(i,j);
//                        t.push_back(p);
//                        result.swap(t);
//                    }
//        
//                }
//            }
//        }
//        if(result.size() > 1){
//            cout<<result[0].x<<" "<<result[0].y<<endl;
//        }
//        else{
//            for(int i = 0;i<result.size(); i++){
//                sort(result.begin(),result.end(),comp);
//            }
//            cout<<result[0].x<<" "<<result[0].y<<endl;
//        }
//        
//    }
//    
//    return 0;®
//}
