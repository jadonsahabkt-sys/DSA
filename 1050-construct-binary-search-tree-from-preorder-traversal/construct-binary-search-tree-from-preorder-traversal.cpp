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
int i=0;
    TreeNode* build(vector<int>& preorder,int lo,int hi){
        if(i== preorder.size()) return nullptr;
        int val=preorder[i];
        if(val <lo || val >hi) return nullptr;
        i++;
        TreeNode* root=new TreeNode(val);
        root->left=build(preorder,lo,val);
        root->right=build(preorder,val,hi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return build(preorder,INT_MIN,INT_MAX);
    }
};