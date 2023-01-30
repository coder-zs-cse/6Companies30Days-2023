// https://leetcode.com/problems/increasing-triplet-subsequence/description/
// Author: Zubin Shah


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, middle = INT_MAX;
        for(auto it:nums){
            if(it<=first) first = it;
            else if(it<=middle) middle = it;
            else return true;
        }
        return false;
    }
};