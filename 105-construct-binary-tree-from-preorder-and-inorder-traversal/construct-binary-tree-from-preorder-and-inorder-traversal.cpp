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
    int i =0;
    TreeNode * build(int s,int e,vector<int>&preorder, vector<int>& inorder,unordered_map<int,int>&mp){
        if(s>e or i>=preorder.size()) return NULL;
        int rootVal = preorder[i];
        i++;
        TreeNode * N = new TreeNode(rootVal);
        int index = mp[rootVal];
        N->left = build(s,index-1,preorder,inorder,mp);
        N->right = build(index+1,e,preorder,inorder,mp);
        return N;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int j=0;j<inorder.size();j++){
            mp[inorder[j]]=j;
        }
        int s = 0;
        int e = inorder.size()-1;
        return build(s,e,preorder,inorder,mp);
    }
};