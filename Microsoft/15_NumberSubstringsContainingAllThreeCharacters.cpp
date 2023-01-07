// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/
// Author: Zubin Shah


class Solution {
public:
    int numberOfSubstrings(string s) {
        int output = 0;
        vector<int> charIndex(3,-1);
        for(int i=0;i<s.length();i++){
            charIndex[s[i]-'a'] = i;
            int leftIndex = min(charIndex[0],min(charIndex[1],charIndex[2]));
            if(leftIndex!=-1) output += leftIndex + 1;
        }
        return output;
    }
};