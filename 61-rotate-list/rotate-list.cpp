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
    int getLen(ListNode* head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLen(head);
        if(len<=1)
            return head;
        k = k % len;
        if(k==0)
            return head;
        ListNode *ptr = head;
        int c = len-k;
        while(--c){
            ptr = ptr->next;
        }
        ListNode * t = ptr->next;
        ListNode * ans = ptr->next;
        ptr->next = NULL;
        while(t->next){
            t = t->next;
        }
        t->next = head;
        return ans;
    }
};