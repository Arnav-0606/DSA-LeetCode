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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        TreeNode * curr = root;
        while(curr!=NULL){
            if(curr->right==NULL){
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else{
                TreeNode * temp = curr->right;
                while(temp->left != NULL and temp->left !=curr){
                    temp = temp->left;
                }
                if(temp->left == NULL){
                    //create the link
                    temp->left = curr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else{
                    //destroy the link
                    temp->left = NULL;
                    curr = curr->left;
                }

            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};