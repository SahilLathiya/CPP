/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isCycle(ListNode *head){
        if(head==NULL || head->next==NULL)
            return false;

        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* ans = NULL;
        if(isCycle(head)==false)
            return ans;
        unordered_map<ListNode*, bool> mpp;
        while(head){
            if(mpp.find(head)!=mpp.end())
                return head;
            mpp[head] = true;
            head = head->next;
        }
        return ans;
    }
};