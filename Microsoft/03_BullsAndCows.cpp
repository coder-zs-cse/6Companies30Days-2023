// https://leetcode.com/problems/bulls-and-cows/
//Author: Zubin Shah


class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls = 0;
        int cows = 0;
        vector<int> freq(10,0);
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                freq[secret[i]-'0']++;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i] != guess[i]){
                if(freq[guess[i]-'0']>0){
                    cows++;
                    freq[guess[i]-'0']--;
                }
            }
            
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";


    }
};