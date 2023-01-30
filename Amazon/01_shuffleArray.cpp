// https://leetcode.com/problems/shuffle-an-array/description/
// Zubin Shah

class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int n = original.size();
        vector<int> output(n,INT_MIN);
        int current = n;
        for(int i=0;i<n;i++){
            int index = rand()%current;
            for(int j=0;j<n;j++){
                if(output[j]==INT_MIN && index-- ==0){
                    output[j] = original[current-1];
                    break;
                }
            }
            current--;
        }
        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */