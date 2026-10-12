/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        parent[root]=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist=0;
        while(!q.empty()){
            if(dist==k) break;
            int sz=q.size();
            while(sz--){
                TreeNode* node=q.front();q.pop();
               for(TreeNode* nxt: {node->left,node->right,parent[node]}){
                    if(nxt && !visited.count(nxt)){
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            dist++;
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};