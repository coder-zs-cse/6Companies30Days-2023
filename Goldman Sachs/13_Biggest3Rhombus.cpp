// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/
// Author: Zubin Shah


class Solution {
public:
void addSumToSolution(int& a, int& b, int& c, int sum) {
        if (sum > a) {
            c = b;
            b = a;
            a = sum;
            return;
        }
        if (sum == a)
            return;
        if (sum > b) {
            c = b;
            b = sum;
            return;
        }
        if (sum == b) return;
        
        if (sum > c) {
            c = sum;
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> upperDiagonal(n,vector<vector<int>>(m,vector<int>(m,0)));
        vector<vector<vector<int>>> lowerDiagonal(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k = 0;k<m/2+1;k++){
                    if(j+k>=m || i+k>=n || j-k<0) break;
                    if(k==0){
                        upperDiagonal[i][j][k] = grid[i][j];
                    }
                    else if(k==1){
                        upperDiagonal[i][j][k] = grid[i][j] + grid[i+1][j+1] + grid[i+1][j-1];
                    }
                    else{
                        upperDiagonal[i][j][k] = upperDiagonal[i+1][j-1][k-1] + upperDiagonal[i+1][j+1][k-1] - upperDiagonal[i+2][j][k-2] - grid[i+2][j] + grid[i][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k = 1;k<m/2+1;k++){
                    if(j+k>=m || i-k<0 || j-k<0) break;
                    if(k==1){
                        lowerDiagonal[i][j][k] = grid[i][j];
                    }
                    else if(k==2){
                        lowerDiagonal[i][j][k] = grid[i][j] + grid[i-1][j+1] + grid[i-1][j-1];
                    }
                    else{
                        lowerDiagonal[i][j][k] = lowerDiagonal[i-1][j-1][k-1] + lowerDiagonal[i-1][j+1][k-1] - lowerDiagonal[i-2][j][k-2] - grid[i-2][j] + grid[i][j];
                    }
                }
            }
        }
        int a,b,c=b=a=-1;
        priority_queue <int, vector<int>, greater<int>> pq;
        vector<int> sum;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m/2+1;k++){
                    if(i+2*k>=n) break;
                    int current = upperDiagonal[i][j][k] + lowerDiagonal[i+2*k][j][k];
                    addSumToSolution(a,b,c,current);
                }
            }
        }
        vector<int> output;
        if(a>-1) output.push_back(a);
        if(b>-1) output.push_back(b);
        if(c>-1) output.push_back(c);
        return output;
    }
};