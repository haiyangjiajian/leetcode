#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    
    int  threeSumClosest(vector<int>& nums,int target) {
        int result = 0;
        if(nums.size()<3)
            return 0;
        int closet = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int k = 0;
        int cha = abs(closet-target);
        while(k<nums.size()){
            left = k+1;
            right = nums.size() - 1;
            while(left<right){
                int curSum = nums[left] + nums[right] + nums[k];
                if(curSum == target){
                    return target;
                }
                if(abs(curSum-target) < abs(closet - target))
                    closet = curSum;
                if(curSum< target){
                    
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

        
        return closet;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> v = {0,1,2};
//    Solution solution;
//    cout<<solution.threeSumClosest(v,0);
//    
//}
