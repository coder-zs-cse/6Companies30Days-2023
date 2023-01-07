// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
// Author: Zubin Shah


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> lastCardIndex;
        int output = INT_MAX;
        for(int i=0;i<cards.size();i++){
            auto check = lastCardIndex.find(cards[i]);
            if(check!=lastCardIndex.end()){
                output = min(output,i - lastCardIndex[cards[i]]+1);
            }
            lastCardIndex[cards[i]] = i;
        }
        if(output == INT_MAX) return -1;
        return output;
    }
};