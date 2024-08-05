/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode* head){
        ListNode *ptr = NULL;
        ListNode *prev = NULL;
        while(head){
            ptr = head;
            head= head -> next;
            ptr -> next = prev;
            prev = ptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }
        if(fast)
            slow = slow->next;
        slow = reverse(slow);
        // while(slow){
        //     cout<<slow->val<<' ';
        //     slow = slow->next;
        // }
        while(slow){
            if(head->val!=slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};