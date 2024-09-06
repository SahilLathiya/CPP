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
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> ans;
        vector<int> t;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();

            if(node==NULL){
                ans.push_back(t);
                t.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                t.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);

        for(int i=0;i<ans.size();i++){
            if(i%2)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};