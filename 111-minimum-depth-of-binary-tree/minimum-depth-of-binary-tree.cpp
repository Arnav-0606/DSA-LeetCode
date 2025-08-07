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
        int lmd = minDepth(root->left);
        int rmd = minDepth(root->right);
        if(lmd==0 and rmd !=0){
            return rmd+1;
        }
        if(rmd ==0 and lmd !=0){
            return lmd+1;
        }
        if(lmd ==0 and rmd ==0){
            return 1;
        }
        return min(lmd,rmd)+1;
    }
};