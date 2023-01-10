// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
// Author: Zubin Shah

class Solution {
public:
    int powe(int n,int power){
        if(power==0) return 1;
        else return n*pow(n,power-1);
    }
    int mod = 1000000007;
    int reverse(int n){
        int output=0;
        while(n){
            output = output*10 + n%10;
            n/=10;
        }
        cout<<output<<endl;
        return output;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        for(auto it:nums){
            rev.push_back(reverse(it));
        }
        vector<int> diff;
        for(int i=0;i<nums.size();i++){
            diff.push_back(nums[i] - rev[i]);
        }
        unordered_map<int,int> freq;
        int output=0;
        for(auto it:diff){
            output = (output%mod + freq[it]%mod)%mod;
            freq[it]++;
        }
        
        return output;
    }
};