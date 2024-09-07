class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        // Check if the path can start from the current node or continue searching in the left or right subtree
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;  // If the linked list is exhausted, it means we found the path
        if (!root) return false; // If the tree is exhausted but the linked list isn't, path not found
        if (head->val != root->val) return false; // Values do not match
        
        // Continue matching the linked list in both left and right subtrees
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};
