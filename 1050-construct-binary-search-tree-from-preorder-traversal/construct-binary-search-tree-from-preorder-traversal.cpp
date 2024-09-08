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
    TreeNode * buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int> &mpp){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        
        TreeNode * root = new TreeNode(preorder[preStart]);
        int inorder_index = mpp[root->val];
        int num_ele_in_left = inorder_index - inStart;
        
        root->left = buildTree(preorder, preStart+1, preStart + num_ele_in_left, inorder, inStart, inorder_index-1, mpp);
        root->right = buildTree(preorder, preStart + num_ele_in_left+1, preEnd, inorder, inorder_index+1, inEnd, mpp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        // Since inorder of BST is always sorted
        int preStart = 0;
        int inStart = 0;
        int preEnd = preorder.size()-1;
        int inEnd = inorder.size()-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode * ans = buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mpp);
        return ans;
    }
};