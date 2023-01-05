// https://leetcode.com/problems/course-schedule/description/
// Author : Zubin Shah

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> subjPreq;
        for(auto it:prerequisites){
            subjPreq[it[0]].push_back(it[1]);
        }
        unordered_set<int> subjStudied;
        for(int i=0;i<numCourses;i++){
            auto check = subjStudied.find(i);
            if(check==subjStudied.end()) {
                unordered_set<int> currentCycle;
                currentCycle.insert(i);
                if(!studyPreq(subjStudied,currentCycle,i,subjPreq)) return false;
            }
        }
        return true;
    }
    bool studyPreq(unordered_set<int> &subjStudied,unordered_set<int> &currentCycle,int current,unordered_map<int,vector<int>> &subjPreq){

        for(int i=0;i<subjPreq[current].size();i++){
            int currentPreq = subjPreq[current][i];
            auto check = subjStudied.find(currentPreq);
            if(check!=subjStudied.end()) continue;
            auto check2 = currentCycle.find(currentPreq);
            if(check2!=currentCycle.end()){
                return false;
            }
            else {

                currentCycle.insert(current);
                if(!studyPreq(subjStudied,currentCycle,currentPreq,subjPreq)){
                    return false;
                }
            }
        }
        subjStudied.insert(current);
        return true;
    }
};