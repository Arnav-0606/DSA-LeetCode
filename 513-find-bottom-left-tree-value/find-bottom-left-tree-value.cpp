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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * f = q.front();
            if(f){
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                q.pop();
            }
            else{
                q.pop();
                if(q.empty()) break;
                q.push(NULL);
                f = q.front();
                ans = f->val;
            }
        }
        return ans;
        
    }
};