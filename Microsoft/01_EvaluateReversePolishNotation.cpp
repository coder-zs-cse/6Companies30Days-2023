// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author: Zubin Shah



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<int(int,int)>> mp = {  //mapping string with function for faster switch case handling
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        }
        stack<int> st;
        for (string& s : tokens) {
            if (!map.count(s)) { //check if this key exists in the map
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
    }
};