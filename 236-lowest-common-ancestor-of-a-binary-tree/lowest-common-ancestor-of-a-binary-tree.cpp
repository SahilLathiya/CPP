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
    bool findNode(TreeNode *root, TreeNode*x, vector<TreeNode*> & path){
        if(root==NULL)
            return false;
        if(root==x){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        bool l = findNode(root->left, x, path);
        if(l)
            return true;
        bool r = findNode(root->right, x, path);
        if(r)
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findNode(root, p, path1);
        findNode(root, q, path2);
        // for(auto x:path1)
        //     cout<<x->val<<' ';
        // cout<<endl;
        // for(auto x:path2)
        //     cout<<x->val<<' ';
        TreeNode * ans;
        for(int i=0;i<min(path1.size(), path2.size());i++){
            if(path1[i]==path2[i])
                ans = path1[i];
            else
                break;
        }
        return ans;
    }
};