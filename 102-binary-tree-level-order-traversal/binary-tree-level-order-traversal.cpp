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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
            
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * curr = q.front();
            if(curr==NULL){
                q.pop();
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                        temp.push_back(curr->val);
                        q.pop();
                        
                        if(curr->left){
                            q.push(curr->left);
                        }
                        if(curr->right){
                            q.push(curr->right);
                        }
                    
                }
        }
        return ans;
    }
};