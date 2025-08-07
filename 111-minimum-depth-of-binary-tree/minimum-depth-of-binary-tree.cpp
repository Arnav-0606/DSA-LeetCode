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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans =1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * n = q.front();
            q.pop();
            if(!n){
                if(!q.empty())q.push(NULL);
                ans++;
                continue;
            }
            if(!n->left and !n->right) return ans;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        return ans;
    }
};