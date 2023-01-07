// https://leetcode.com/problems/valid-square/description/
// Author: Zubin Shah


class Solution {
public:
     int distance(int a1,int b1,int a2,int b2){
        int output =  (a2-a1)*(a2-a1) + (b2-b1)*(b2-b1);
        cout<<output<<endl;
        return output;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int> lengthSquare;
        lengthSquare[distance(p1[0],p1[1],p2[0],p2[1])]++;
        lengthSquare[distance(p1[0],p1[1],p3[0],p3[1])]++;
        lengthSquare[distance(p1[0],p1[1],p4[0],p4[1])]++;
        lengthSquare[distance(p2[0],p2[1],p3[0],p3[1])]++;
        lengthSquare[distance(p2[0],p2[1],p4[0],p4[1])]++;
        lengthSquare[distance(p3[0],p3[1],p4[0],p4[1])]++;
        if(lengthSquare.size()>2) return false;
        if(lengthSquare[0]>0) return false;
        return true;
    }
};