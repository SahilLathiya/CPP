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
    TreeNode* preOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* l = preOrder(root->left, p, q);
        TreeNode* r = preOrder(root->right, p, q);
        if(l && r)
            return root;
        if(l)
            return l;
        if(r)
            return r;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return preOrder(root, p, q);
    }
};