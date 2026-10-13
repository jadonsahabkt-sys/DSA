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
    unordered_map<int,int>idx;
    int postIdx;
    TreeNode* build(vector<int>& postorder,int left,int right){
        if(left>right) return nullptr;
        int rootVal=postorder[postIdx--];
        TreeNode* root=new TreeNode(rootVal);

        int mid=idx[rootVal];
        root->right=build(postorder,mid+1,right);
        root->left=build(postorder,left,mid-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        idx[inorder[i]]=i;
        postIdx=n-1;
        return  build(postorder,0,n-1);

    }
};