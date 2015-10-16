//
//  Other_HuluOnline.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/26.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <string>
using namespace std;
int searchIndex(vector<int> a, int t){
    int start = 0;
    int end = a.size() - 1;
    while(start <= end){
        int m = (start + end)/2;
        if(a[m] == t){
            while(m - 1>=0 && a[m-1] == a[m])
                m--;
            return m;
        }
        else if(a[m] < t)
            start = m + 1;
        else
            end = m - 1;
    }
    return start;
}
int searchIndex2(vector<int> a, int t){
    int start = 0;
    int end = a.size() - 1;
    while(start <= end){
        int m = (start + end)/2;
        if(a[m] == t){
            while(m + 1 < a.size() && a[m+1] == a[m])
                m++;
            return m;
        }
        else if(a[m] < t)
            start = m + 1;
        else
            end = m - 1;
    }
    return start-1;
}
int searchIndex3(vector<int> a, int t){
    if(t < a[0])
        return 0;
    for(int i = 0;i < a.size() - 1;i++){
        if(a[i] == t)
            return i;
        if(t > a[i] && t <= a[i + 1])
            return i+1;
    }
    return a.size();
}

int searchIndex4(vector<int> a, int t){
    int  l = a.size();
    if(t > a[l - 1])
        return l - 1;
    for(int i = l -1 ;i > 0;i-- ){
        if(t == a[i])
            return i;
        if(t < a[i] && t >= a[i - 1])
            return i - 1;
    }
    return -1;
}

//int main(int argc, const char * argv[])
//{
//    int n;
//    cin>>n;
//    vector<int> house(n,0);
//    vector<long long> rain(n,0);
//    for(int i = 0; i< n;i ++){
//        int a;
//        cin>>a;
//        house[i] = a;
//    }
//    int m;
//    cin>>m;
//    while(m>0){
//        int x, y, z;
//        cin>>x;
//        cin>>y;
//        cin>>z;
//        int start = searchIndex(house,x);
//        int end = searchIndex2(house,y);
//        cout<<"start:"<<start<<endl;
//        cout<<"end:"<<end<<endl;
//        for(int i = start; i<=end;i++)
//            rain[i] += z;
//        m--;
//    }
//    for(int i = 0;i < rain.size(); i++)
//        cout<<rain[i]<<endl;
//}
//

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int a, b;
//    while(cin >> a >> b) {
//        cout << a + b << endl;
//    }
//    return 0;
//}
