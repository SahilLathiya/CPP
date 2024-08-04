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
        int carry =0;
        int sum =0;
        int ans = 0;
        ListNode* head = NULL;
        ListNode* ptr;
        ListNode* prev;

        while(l1 && l2){
            sum = (l1->val+l2->val);
            ans = (sum + carry)%10;
            carry = (sum + carry)/10;

            ptr = new ListNode(ans);
            if(!head)
                head = ptr;
            else{
                prev->next = ptr;
            }
            prev = ptr;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1){
            sum = (l1->val)%10;
            ans = (sum + carry)%10;
            carry = (sum + carry)/10;
            
            ptr = new ListNode(ans);
            prev->next = ptr;
            prev = ptr;
            l1 = l1->next;
        }
        while(l2){
            sum = (l2->val)%10;
            ans = (sum + carry)%10;
            carry = (sum + carry)/10;
            ptr = new ListNode(ans);
            prev->next = ptr;
            prev = ptr;
            l2 = l2->next;
        }

        if(carry){
            ptr = new ListNode(carry);
            prev->next = ptr;
            prev = ptr;
        }


        return head;
    }
};