// https://leetcode.com/problems/combination-sum-iii/
// Author: Zubin Shah



class Solution {
public:
    void combination(int index,int sum,int k,int n,int data,unordered_set<int> &currentComb,int current){
        if(index==k){
            if(sum!=n) return ;
            currentComb.insert(data);
            return ;
        }
        for(int j=current;j<=9;j++){
            if(1<<j & data) continue;
            if(sum+j<=n){
                data ^= 1<<j;
                combination(index+1,sum+j,k,n,data,currentComb,j+1);
                data ^= 1<<j;
            }
        }
        
    }
    vector<int> numToVector(int data){
        // cout<<data<<endl;
        vector<int> output;
        for(int i=0;(1<<i) <= data; i++){
            if(1<<i & data) output.push_back(i);
        }
        return output;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_set<int> recordComb;
        int data=0;  //using bitwise techniques to keep a record of visited numbers
       
        combination(0,0,k,n,data,recordComb,1);
        vector<vector<int>> output;
        for(auto it:recordComb){
            output.push_back(numToVector(it));
        }
        return output;
    }
};