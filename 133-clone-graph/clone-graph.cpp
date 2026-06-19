/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<int,Node*>mp;
        Node* f = new Node(node->val);
        mp[node->val] = f;
        unordered_map<int,bool>vis;
        vis[node->val] = true;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            for(auto &ngb :n->neighbors){
                Node* ne;
                if(mp.count(ngb->val)==0){
                    ne = new Node(ngb->val);
                    mp[ngb->val] = ne;
                }
                else{
                    ne = mp[ngb->val];
                }
                    mp[ne->val]->neighbors.push_back(mp[n->val]);
                    // mp[n->val]->neighbors.push_back(mp[ne->val]);
                if(!vis[ngb->val]){
                    q.push(ngb);
                    vis[ngb->val] = true;
                }
            }
        }
        return f;
                
    }
};