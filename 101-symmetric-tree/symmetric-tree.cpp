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
    bool isTreesSame(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if((!root1 && root2) || (!root2 && root1))
            return false;
        if(root1->val != root2->val)
            return false;
        bool l = isTreesSame(root1->left, root2->right);
        bool r = isTreesSame(root1->right, root2->left);
        // cout<<root1->val<<' '<<int(l&r)<<'\n';
        return l&r;
    }
    bool isSymmetric(TreeNode* root) {
        return isTreesSame(root->left, root->right);
    }
};