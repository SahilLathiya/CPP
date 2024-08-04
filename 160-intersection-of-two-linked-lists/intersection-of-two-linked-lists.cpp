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
    int getCnt(ListNode *headA){
        int cnt = 0;
        while(headA){
            cnt++;
            headA = headA->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = getCnt(headA);
        int c2 = getCnt(headB);
        // cout<<c1<<' '<<c2<<endl;
        // cout<<headA->val<<' '<<headB->val<<endl;

        ListNode *a = headA;
        ListNode *b = headB;

        ListNode* ans = NULL;
        if(c1<c2){
            int diff = c2-c1;
            while(diff){
                b = b->next;
                diff--;
            }
        }
        else{
            int diff = c1-c2;
            while(diff){
                a = a->next;
                diff--;
            }
        }
        while(a){
            if(a==b)
                return a;
            a = a->next;
            b = b->next;
        }
        return ans;
    }
};