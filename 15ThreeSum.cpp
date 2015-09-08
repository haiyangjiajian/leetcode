#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        unordered_map<int,int> index;
        unordered_map<int,int>::iterator it;
        for(int i = 0;i<nums.size();i++)
            index.insert(pair<int,int>(nums[i],i));
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(i!=j){
                    it = index.find(0-nums[i]-nums[j]);
                    if(it!=index.end()){
                        if(it->second== i || it->second!=j)
                            continue;
                        vector<int> tuple;
                        tuple.push_back(nums[i]);
                        tuple.push_back(nums[j]);
                        tuple.push_back(it->first);
                        result.push_back(tuple);
                    }
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = (int)(nums.size() - 1);
        int k = 0;
        while(k<nums.size() && nums[k]<=0){
            left = k+1;
            right = nums.size() - 1;
            while(left<right){
                if(nums[left] + nums[right] + nums[k] == 0){
                    vector<int> tuple;
                    tuple.push_back(nums[k]);
                    tuple.push_back(nums[left]);
                    tuple.push_back(nums[right]);
                    result.push_back(tuple);
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                    right--;
                    while(left<right && nums[right] == nums[right+1]) right -- ;

                }
                else if(nums[left] + nums[right] + nums[k] < 0){
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                }
                else{
                    right--;
                    while(left<right && nums[right] == nums[right+1]) right -- ;

                }
                
            }
            k++;
            while (k < left && nums[k] == nums[k-1]) k++;

        }
        return result;
        
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> v = {3,-2,1,0};
//    Solution solution;
//    vector<vector<int>> result = solution.threeSum(v);
//    cout<<"12"<<endl;
////    cout<<result[0][0]<<endl;
////    cout<<result[0][1]<<endl;
////    cout<<result[0][2]<<endl;
//
//}
