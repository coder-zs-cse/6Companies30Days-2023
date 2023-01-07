// https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
// Author: Zubin Shah


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int primary = 0, secondary = 0, tertiary = 0;
        unordered_map<int,int> numFreq;
        for(int i=0;i<nums.size();i++){
            numFreq[nums[i]]++;
        }
        for(int i = -1000;i<=1000;i++){
            if(primary+secondary==0){
                tertiary = min(tertiary , numFreq[i]);
                primary = max(0,numFreq[i] - tertiary);
            }
            else{
                if(primary + secondary > numFreq[i]) {
                    cout<<i<<endl;
                    return false;
                }
                else{
                    
                    int temp = numFreq[i] - secondary - primary;
                    int prim = primary;
                    primary = max(0,temp - tertiary);
                    if(temp<=tertiary) tertiary = temp;
                    tertiary += secondary;
                    secondary = prim;
                }
            }
           
            if(i>=10 && i<=100){
                cout<<i<<": "<<numFreq[i]<<" "<<primary<<" "<<secondary<<" "<<tertiary<<endl;
            }
        }
        cout<<primary<<" "<<secondary<<endl;
        if(primary + secondary !=0 ) return false;
        return true;
    }
};