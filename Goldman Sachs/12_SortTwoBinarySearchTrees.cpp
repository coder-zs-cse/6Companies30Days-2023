// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/
// Author: Zubin Shah


class Solution {
public:
    void inorderTraversal(TreeNode* root,vector<int> &output) {
        if(!root) return ;
        inorderTraversal(root->left,output);
        output.push_back(root->val);
        inorderTraversal(root->right,output);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> leftVector, rightVector;
        inorderTraversal(root1,leftVector);
        inorderTraversal(root2,rightVector);
        vector<int> output;
        int i,j=i=0;
        while(i<leftVector.size() && j<rightVector.size()){
            if(leftVector[i]<rightVector[j]){
                output.push_back(leftVector[i]);
                i++;
            }
            else{
                output.push_back(rightVector[j]);
                j++;
            }
        }
        while(i<leftVector.size()){
            output.push_back(leftVector[i]);
            i++;
        }
        while(j<rightVector.size()){
            output.push_back(rightVector[j]);
            j++;
        }
        return output;
    }
};