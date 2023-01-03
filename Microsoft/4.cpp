// https://leetcode.com/problems/rotate-function/description/
// Author: Zubin Shah

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int func = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            func += i*nums[i];
            sum+=nums[i];
        }
        int output=func;
        int current  = func;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            current = current +  sum -n* nums[i];
            output = max(output,current);
        }
        return output;

    }
};