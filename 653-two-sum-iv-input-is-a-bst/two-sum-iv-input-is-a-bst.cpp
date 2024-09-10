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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* r = root;
        while(r){
            st.push(r);
            r = r->left;
        }
    }
    
    int next() {
        TreeNode * node = st.top();
        st.pop();
        if(node->right){
            TreeNode* r = node->right;
            while(r){
                st.push(r);
                r = r->left;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class BSTIterator1 {
public:
    stack<TreeNode*> st;
    BSTIterator1(TreeNode* root) {
        TreeNode* r = root;
        while(r){
            st.push(r);
            r = r->right;
        }
    }
    
    int before() {
        TreeNode * node = st.top();
        st.pop();
        if(node->left){
            TreeNode* r = node->left;
            while(r){
                st.push(r);
                r = r->right;
            }
        }
        return node->val;
    }
    
    bool hasBefore() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTIterator bstN(root);
        BSTIterator1 bstB(root);

        int x = bstN.next();
        int y = bstB.before();
        while(x<y){
            if(x+y==k)
                return true;
            else if(x+y<k)
                x = bstN.next();
            else
                y = bstB.before();
        }
        return false;
    }
};