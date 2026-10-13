/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s;
       ser(root,s);
       return s;
      
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
  private:
   void ser(TreeNode* node,string& s){
    if(!node){
        s+="N,";
        return;
    }
    s+=to_string(node->val)+",";
    ser(node->left,s);
    ser(node->right,s);
   
   }
   TreeNode* build(stringstream& ss){
    string tok;
    getline(ss,tok,',');
    if(tok=="N") return nullptr;

    TreeNode* node=new TreeNode(stoi(tok));
    node->left=build(ss);
    node->right=build(ss);
    return node;
   }  
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));