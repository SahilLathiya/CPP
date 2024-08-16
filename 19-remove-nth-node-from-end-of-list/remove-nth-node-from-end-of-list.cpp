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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr->next;
        }

        
        int t = len - (n-1);
        if(t==1)
            return head->next;
        ListNode * temp = head;
        ListNode * prev = NULL;
        while(--t){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }
};