//
//  Other_360Online.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/15.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <string>
#include <strstream>
using namespace std;
bool isSushu(int a){
    int i=2;
    bool flag = true;
    for(;i<=a/2;i++)
        if(a%i==0)
        {
            flag=false;
            break;
        }
    return flag;
}
vector<int> divide(int a){
    vector<int> result;
    if(isSushu(a)){
        result.push_back(a);
        return result;
    }
    int temp = a;
    for(int i = 2; i <= a/2;){
        if(isSushu(i) && temp%i == 0){
            result.push_back(i);
            temp = temp/i;
            if(isSushu(temp)){
                result.push_back(temp);
                break;
            }
        }
        else{
            i++;
        }
        
    }
    sort(result.begin(),result.end());
    return result;
    
}
void output(vector<int> a,char draw[10][5][3]){
    strstream ss;
   
        for(int j = 0;j<5;j++){
            for(int i = 0;i < a.size(); i++){
                string s;
                ss << a[i];
                ss >> s;
                for(int m = 0; m<s.size();m++){
                    for(int k = 0;k < 3;k++){
                        if( draw[9][j][k] == '1')
                            cout<<'|';
                        else
                            cout<<draw[9][4][1];
                    }
                }
                if(j == 2 && i != a.size() - 1)
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
            
        }
    cout<<"a"<<endl;
}
//int main(int argc, const char * argv[])
//{
//    char draw[10][5][3];
//    char array1[3] = {' ','-',' '};
//    char array2[3] = {'1', ' ', '1'};
//    char array3[3] = {' ',' ',' '};
//    char array4[3] = {'1', ' ', '1'};
//    char array5[3] = {' ','-',' '};
//    memcpy(draw[0][0],array1,sizeof(array1));
//    memcpy(draw[0][1],array2,sizeof(array2));
//    memcpy(draw[0][2],array3,sizeof(array3));
//    memcpy(draw[0][3],array4,sizeof(array4));
//    memcpy(draw[0][4],array5,sizeof(array5));
//    
//    char array11[3] = {' ',' ',' '};
//    char array12[3] = {' ', ' ', '1'};
//    char array13[3] = {' ',' ',' '};
//    char array14[3] = {' ', ' ', '1'};
//    char array15[3] = {' ',' ',' '};
//    memcpy(draw[1][0],array11,sizeof(array11));
//    memcpy(draw[1][1],array12,sizeof(array12));
//    memcpy(draw[1][2],array13,sizeof(array13));
//    memcpy(draw[1][3],array14,sizeof(array14));
//    memcpy(draw[1][4],array15,sizeof(array15));
//    
//    char array21[3] = {' ','-',' '};
//    char array22[3] = {' ', ' ', '1'};
//    char array23[3] = {' ','-',' '};
//    char array24[3] = {'1', ' ', ' '};
//    char array25[3] = {' ','-',' '};
//    memcpy(draw[2][0],array21,sizeof(array21));
//    memcpy(draw[2][1],array22,sizeof(array22));
//    memcpy(draw[2][2],array23,sizeof(array23));
//    memcpy(draw[2][3],array24,sizeof(array24));
//    memcpy(draw[2][4],array25,sizeof(array25));
//    
//    char array31[3] = {' ','-',' '};
//    char array32[3] = {' ', ' ', '1'};
//    char array33[3] = {' ','-',' '};
//    char array34[3] = {' ', ' ', '1'};
//    char array35[3] = {' ','-',' '};
//    memcpy(draw[3][0],array31,sizeof(array31));
//    memcpy(draw[3][1],array32,sizeof(array32));
//    memcpy(draw[3][2],array33,sizeof(array33));
//    memcpy(draw[3][3],array34,sizeof(array34));
//    memcpy(draw[3][4],array35,sizeof(array35));
//    
//    char array41[3] = {' ',' ',' '};
//    char array42[3] = {'1', ' ', '1'};
//    char array43[3] = {' ','-',' '};
//    char array44[3] = {' ', ' ', '1'};
//    char array45[3] = {' ',' ',' '};
//    memcpy(draw[4][0],array41,sizeof(array41));
//    memcpy(draw[4][1],array42,sizeof(array42));
//    memcpy(draw[4][2],array43,sizeof(array43));
//    memcpy(draw[4][3],array44,sizeof(array44));
//    memcpy(draw[4][4],array45,sizeof(array45));
//    
//    char array51[3] = {' ','-',' '};
//    char array52[3] = {'1', ' ', ' '};
//    char array53[3] = {' ','-',' '};
//    char array54[3] = {' ', ' ', '1'};
//    char array55[3] = {' ','-',' '};
//    memcpy(draw[5][0],array51,sizeof(array51));
//    memcpy(draw[5][1],array52,sizeof(array52));
//    memcpy(draw[5][2],array53,sizeof(array53));
//    memcpy(draw[5][3],array54,sizeof(array54));
//    memcpy(draw[5][4],array55,sizeof(array55));
//    
//    char array61[3] = {' ','-',' '};
//    char array62[3] = {'1', ' ', ' '};
//    char array63[3] = {' ','-',' '};
//    char array64[3] = {'1', ' ', '1'};
//    char array65[3] = {' ','-',' '};
//    memcpy(draw[6][0],array61,sizeof(array61));
//    memcpy(draw[6][1],array62,sizeof(array62));
//    memcpy(draw[6][2],array63,sizeof(array63));
//    memcpy(draw[6][3],array64,sizeof(array64));
//    memcpy(draw[6][4],array65,sizeof(array65));
//    
//    char array71[3] = {' ','-',' '};
//    char array72[3] = {' ', ' ', '1'};
//    char array73[3] = {' ',' ',' '};
//    char array74[3] = {' ', ' ', '1'};
//    char array75[3] = {' ',' ',' '};
//    memcpy(draw[7][0],array71,sizeof(array71));
//    memcpy(draw[7][1],array72,sizeof(array72));
//    memcpy(draw[7][2],array73,sizeof(array73));
//    memcpy(draw[7][3],array74,sizeof(array74));
//    memcpy(draw[7][4],array75,sizeof(array75));
//    
//    char array81[3] = {' ','-',' '};
//    char array82[3] = {'1', ' ', '1'};
//    char array83[3] = {' ','-',' '};
//    char array84[3] = {'1', ' ', '1'};
//    char array85[3] = {' ','-',' '};
//    memcpy(draw[8][0],array81,sizeof(array81));
//    memcpy(draw[8][1],array82,sizeof(array82));
//    memcpy(draw[8][2],array83,sizeof(array83));
//    memcpy(draw[8][3],array84,sizeof(array84));
//    memcpy(draw[8][4],array85,sizeof(array85));
//
//    char array91[3] = {' ','-',' '};
//    char array92[3] = {'1', ' ', '1'};
//    char array93[3] = {' ','-',' '};
//    char array94[3] = {' ', ' ', '1'};
//    char array95[3] = {' ','-',' '};
//    memcpy(draw[9][0],array91,sizeof(array91));
//    memcpy(draw[9][1],array92,sizeof(array92));
//    memcpy(draw[9][2],array93,sizeof(array93));
//    memcpy(draw[9][3],array94,sizeof(array94));
//    memcpy(draw[9][4],array95,sizeof(array95));
//    cout<<draw[9][4][1]<<endl;
//    int a = 0;
//    while(cin>>a){
//        vector<int> result = divide(a);
//        output(result,draw);
//    }
//}
