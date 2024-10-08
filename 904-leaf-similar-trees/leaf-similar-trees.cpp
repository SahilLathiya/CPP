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
    void preOrder(TreeNode * root, vector<int> & arr){
        if(!root)
            return;
        if(!root->left && !root->right)
            arr.push_back(root->val);
        preOrder(root->left, arr);
        preOrder(root->right, arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        preOrder(root1, l1);
        preOrder(root2, l2);

        return l1==l2;
    }
};