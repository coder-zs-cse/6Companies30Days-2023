// https://leetcode.com/problems/factorial-trailing-zeroes/description/
// Authot: Zubin Shah


class Solution {
public:
    int trailingZeroes(int n) {
        int factor5 = 0;
        int power5=1;
        while(n>=(int)pow(5,power5)){
            factor5+=n/pow(5,power5);
            power5++;
        }
        return factor5;
    }
};