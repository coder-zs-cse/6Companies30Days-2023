// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/
// Zubin Shah


class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(bottom-1);
        special.push_back(top+1);
        sort(special.begin(),special.end());
        int output =0;
        int n  = special.size();
        for(int i=1;i<n;i++){
            output = max(output, special[i] - special[i-1] -1);
        }
        return output;
    }
};