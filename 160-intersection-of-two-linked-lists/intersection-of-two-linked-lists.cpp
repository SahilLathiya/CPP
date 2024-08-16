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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode * ptrA = headA;
        ListNode * ptrB = headB;
        while(ptrA){
            len1++;
            ptrA = ptrA->next;
        }
        while(ptrB){
            len2++;
            ptrB = ptrB->next;
        }

        ptrA = headA;
        ptrB = headB;
        while(ptrA && len1>len2){
            len1--;
            ptrA = ptrA->next;
        }
        while(ptrB && len1<len2){
            len2--;
            ptrB = ptrB->next;
        }

        while(ptrA && ptrB){
            if(ptrA==ptrB)
                return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;

        }
        return NULL;
    }
};