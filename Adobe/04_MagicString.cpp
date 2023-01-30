// https://leetcode.com/problems/magical-string/description/
// Author: Zubin Shah

class Solution {
public:
    int magicalString(int n) {
        int index = 2;
        string magic = "122";
        char next = '1';
        int current = 3;
        int output=1;
        while(current<n){
            int temp = magic[index]-'0';
            while(temp>0){
                magic += next;
                if(next=='1') output++;
                temp--;
                current++;
            }
            index++;
            next = next=='1' ? '2':'1';
        }
        if(current==n+1){
            if(magic[n]=='1') output--;
        }
        cout<<magic;
        return output;
    }
};