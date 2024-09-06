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
    int findHeight(TreeNode * root, int &ans){
        if(!root)
            return 0;
        int lh = findHeight(root->left, ans);
        lh = max(0, lh);
        int rh = findHeight(root->right, ans);
        rh = max(0, rh);
        ans = max(ans, lh+rh+root->val);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findHeight(root, ans);
        return ans;
    }
};