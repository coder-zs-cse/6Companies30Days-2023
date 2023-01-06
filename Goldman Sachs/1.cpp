// https://leetcode.com/problems/max-points-on-a-line/description/
// Author: Zubin Shah


class Solution {
public:
    double calcSlope(int a1,int b1,int a2,int b2){
        double slope;
        if(a2==a1)  {
            slope = INT_MAX;
        }
        else {
            if(b2==b1) slope = 0;
            else slope = (double)(b2-b1)/(double)(a2-a1);
        }
        return slope;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int output=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> slope;
            for(int j=i+1;j<n;j++){
                
                slope[calcSlope(points[i][0],points[i][1],points[j][0],points[j][1])]++;
            }
            for(auto it:slope){
                output = max(output,it.second);
            }

        }
        return output+1;

    }
};