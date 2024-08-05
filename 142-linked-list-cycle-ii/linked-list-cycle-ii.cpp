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
    ListNode *isCycle(ListNode *head){
        if(head==NULL || head->next==NULL)
            return NULL;

        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return fast;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* ans = NULL;
        ListNode* fast = isCycle(head);
        if(!fast)
            return ans;
        ListNode* slow = fast;
        while(head){
            do{
                if(slow==head)
                    return slow;
                slow = slow->next;
            }while(slow!=fast);
            head = head->next;
        }
        return ans;
    }
};