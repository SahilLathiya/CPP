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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mpp){
        if(preEnd<preStart || inEnd<inStart)
            return NULL;
        
        TreeNode * root = new TreeNode(preorder[preStart]);
        int inorder_index = mpp[preorder[preStart]];
        int num_of_ele_in_left = inorder_index - inStart;
        root->left = solve(preorder, preStart+1, preStart+num_of_ele_in_left, inorder, inStart, inorder_index-1, mpp);
        root->right = solve(preorder, preStart+num_of_ele_in_left+1, preEnd, inorder, inorder_index+1, inEnd, mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        int inStart = 0;
        int preEnd = preorder.size()-1;
        int inEnd = inorder.size()-1;

        unordered_map<int, int> mpp;
        for(int i=0;i<inorder.size();i++)
            mpp[inorder[i]] = i;
        
        return solve(preorder, preStart, preEnd, 
                     inorder, inStart, inEnd, mpp);
    }

};