//https://leetcode.com/problems/maximum-good-people-based-on-statements/description/
// Author: Zubin Shah

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int maxgood=0;
        for(int mask=0;mask< (1<<n);mask++){
            bool assumption=true;
            for(int i=0;i<n && assumption==true;i++){
                if(mask & 1<<i) {
                    for(int j=0;j<n;j++){
                        if (statements[i][j]==!((1<<j) & mask)){
                            assumption=false;
                            break;
                        }
                        // else if(statements[i][j]==(1<<j & mask))
                    }
                }
            }
            if(assumption==true){
                maxgood=max(__builtin_popcount(mask),maxgood);
            }
        }
        return maxgood;
    }
};
// if (a[i][j] == 1)
// {  if (!(mask & (1 << j))) can = false; }

// if (a[i][j] == 0)
// {  if ((mask & (1 << j)))   can = false; }