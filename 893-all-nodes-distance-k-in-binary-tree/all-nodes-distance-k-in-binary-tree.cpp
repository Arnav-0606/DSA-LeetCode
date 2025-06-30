class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, vector<TreeNode*>> adj;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->left != NULL){
                adj[front].push_back(front->left);
                adj[front->left].push_back(front);
                q.push(front->left);
            }

            if(front->right != NULL){
                adj[front].push_back(front->right);
                adj[front->right].push_back(front);
                q.push(front->right);
            }
        }

        map<TreeNode*, int> dis;
        q.push(target);
        dis[target] = 0;

        set<TreeNode*> vis;
        vis.insert(target);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            for(TreeNode* ngb:adj[cur]){
                if(vis.find(ngb) == vis.end()){
                    vis.insert(ngb);
                    q.push(ngb);
                    dis[ngb] = dis[cur]+1;
                }
            }
        }

        vector<int> ans;

        for(auto [node, d]:dis){
            if(d==k){
                ans.push_back(node->val);
            }
        }

        return ans;
    }
};