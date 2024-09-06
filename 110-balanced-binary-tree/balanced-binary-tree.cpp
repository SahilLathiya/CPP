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
    int findHeight(TreeNode* root, bool &ans){
        if(root==NULL)
            return 0;
        int lh = findHeight(root->left, ans);
        int rh = findHeight(root->right, ans);
        if(abs(lh-rh)>1){
            ans = false;
            return 0;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        findHeight(root, ans);
        return ans;
    }
};