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
    void inorder(TreeNode * root, unordered_map<int,bool> &mpp){
        if(!root)
            return;
        inorder(root->left, mpp);
        mpp[root->val] = true;
        inorder(root->right, mpp);
    }
    bool solve(TreeNode * root, int k, unordered_map<int,bool> &mpp){
        if(!root)
            return false;

        if(mpp[k - root->val] && root->val!=(k - root->val))
            return true;
        bool l = solve(root->left, k, mpp);
        bool r = solve(root->right, k, mpp);
        return l | r;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode * r = root;
        unordered_map<int,bool> mpp;
        inorder(r, mpp);

        return solve(r, k, mpp);
    }
};