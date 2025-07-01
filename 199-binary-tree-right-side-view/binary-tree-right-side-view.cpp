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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        int v;
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(v);
                if(!q.empty()) q.push(NULL);
            }
            else{
            v = curr->val;
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            }
        }
        return ans;
        
    }
};