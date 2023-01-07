// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
// AUthor : Zubin Shah



class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int localMax = nums[0];
        int n = nums.size();
        int unsortedLIndex = 0;
        int discMin = INT_MAX;
        int discMax = INT_MIN;
        int unsortedRIndex = n-1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                if(nums[i]<discMin) {
                    discMin = nums[i];
                    unsortedLIndex = i;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                if(nums[i]>discMax) {
                    discMax = nums[i];
                    unsortedRIndex = i;
                }
            }
        }
        if(discMin==INT_MAX) return 0;
        for(int i=0;i<n;i++){
            if(nums[unsortedLIndex]<nums[i]){
                unsortedLIndex = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[unsortedRIndex]>nums[i]){
                unsortedRIndex = i;
                break;
            }
        }

        int output = unsortedRIndex - unsortedLIndex + 1;

        return output;
    }
};