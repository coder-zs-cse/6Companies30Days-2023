// https://leetcode.com/problems/maximum-good-people-based-on-statements/description/
// Zubin Shah


class Solution {
public:
    bool Valid(vector<vector<int>>& statements,int current,int n){
        for(int i=0;i<n;i++){
            if(1<<i & current){
                for(int j=0;j<n;j++){
                    if(statements[i][j]==1){
                        if(!(1<<j & current)) return false;
                    }
                    else if(statements[i][j]==0) {
                        if(1<<j & current) return false;
                    }
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int totalComb = 1 << n;
        int output=0;
        for(int i=0;i<totalComb;i++){
            int current = i;
            if(Valid(statements,current,n)){
                output = max(output,__builtin_popcount(current));
            }
        }
        return output;
    }


};