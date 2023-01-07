// https://leetcode.com/problems/number-of-boomerangs/description/
// Author: Zubin Shah


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int output = 0;
        for(int i=0;i<points.size();i++){
            unordered_map<int,int> distanceFreq;
            for(int j=0;j<points.size();j++){
                int distance = pow(points[j][1] - points[i][1],2) + pow(points[j][0] - points[i][0],2);
                distanceFreq[distance]++;
            }
            for(auto it:distanceFreq){
                output += it.second * (it.second-1);
            }
        }
        return output;
    }
};