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
    bool preOrder(TreeNode * root, long long int range_min, long long int range_max){
        if(!root)
            return true;
        
        if(range_min>=root->val || range_max<=root->val)
            return false;
        
        bool l = preOrder(root->left, range_min, root->val);
        bool r = preOrder(root->right, root->val, range_max);
        return l&r;
    }
    bool isValidBST(TreeNode* root) {
        long long int range_min = (long long int)INT_MIN-1;
        long long int range_max = (long long int)INT_MAX+1;

        return preOrder(root, range_min, range_max);
    }
};