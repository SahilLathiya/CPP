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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode * ans = new ListNode();
        ListNode * ptr = ans;
        while(l1 && l2){
            sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1){
            sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1 -> next;
        }
        while(l2){
            sum = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l2 = l2 -> next;
        }
        if(carry){
            ptr->next = new ListNode(carry);
        }
        return ans->next;
    }
};