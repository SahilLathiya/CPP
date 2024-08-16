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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return 0;
        ListNode * prev = head;
        head = head->next;
        while(head && head->next){
            if(prev==head)
                return 1;
            head = head->next->next;
            prev = prev->next;
        }
        return 0;
    }
};