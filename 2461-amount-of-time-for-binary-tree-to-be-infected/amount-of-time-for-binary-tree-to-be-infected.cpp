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
    unordered_map<int,vector<int>>adj;
    void creategraph(TreeNode * root){
        if(!root) return;
        int u = root->val;
        if(root->left != NULL){
            int v = root->left->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(root->right != NULL){
            int v = root->right->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        creategraph(root->left);
        creategraph(root->right);
    }
        
    int amountOfTime(TreeNode* root, int start) {
       creategraph(root);
       map<int,bool>vis;
       int levels = -1;
       queue<int>q;
       q.push(start);
       vis[start] = true;
       q.push(-1);
       while(!q.empty()){
        int f = q.front();
        q.pop();
        if(f==-1){
            if(!q.empty())q.push(-1);
            levels++;
        }
        for(auto ngb : adj[f]){
            if(!vis[ngb]){
                vis[ngb] = true;
                q.push(ngb);
            }
        }
       }
        return levels;
    }
};