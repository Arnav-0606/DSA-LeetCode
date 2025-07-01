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
    int counter(TreeNode * root,int msf){
        //base case
        if(root==NULL) return 0;
        //recursive case
        int t=0;
        if(root->val>=msf){
            t=1;
            msf = root->val;
        }
        return counter(root->left,msf) + counter(root->right,msf)+t;
    }
    int goodNodes(TreeNode* root) {
        return counter(root,root->val);
    }
};