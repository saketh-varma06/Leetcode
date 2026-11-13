/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        vector<int>part;
        part.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(accumulate(part.begin(),part.end(),0)==targetSum){
                ans.push_back(part);
            }
            return ans;
        }
        vector<vector<int>>left=pathSum(root->left,targetSum-root->val);
        for(auto i:left){
            vector<int>temp=part;
            temp.insert(temp.end(),i.begin(),i.end());
            ans.push_back(temp);
        }
        vector<vector<int>>right=pathSum(root->right,targetSum-root->val);
        for(auto i:right){
            vector<int>temp=part;
            temp.insert(temp.end(),i.begin(),i.end());
            ans.push_back(temp);
        }
        return ans;
    }
};