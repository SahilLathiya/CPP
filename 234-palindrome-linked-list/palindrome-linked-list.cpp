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
    ListNode* reverse(ListNode * head){
        ListNode * prev1 = NULL;
        ListNode * prev2 = NULL;
        ListNode * curr = head;
        
        while(curr){
            prev1 = curr;
            curr = curr->next;
            prev1->next = prev2;
            prev2 = prev1;
        }
        return prev1;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        if(len<=1)
            return true;

        ptr = head;
        int cnt = 0;
        while(cnt<len/2){
            cnt++;
            ptr = ptr->next;
        }
        
        ptr = reverse(ptr);

        while(ptr){
            if(ptr->val != head->val)
                return false;
            ptr = ptr -> next;
            head = head -> next;
        }
        return true;
    }
};