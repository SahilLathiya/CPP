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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr->next;
        }
        if(len==0)
            return head;
        k = k % len;
        if(k==0)
            return head;

        ptr = head;
        
        for(int i = 1; i<len-k; i++){
            ptr = ptr->next;
        }
        ListNode * ptr2 = ptr->next;
        ptr->next = NULL;
        ptr = ptr2;
        while(ptr && ptr->next)
            ptr = ptr->next;
        if(ptr)
            ptr->next = head;
        return ptr2;
    }
};