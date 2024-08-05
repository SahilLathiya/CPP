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
    vector<ListNode*> reverse(ListNode* head, ListNode *last, ListNode* prev){
        // ListNode *prev = NULL;
        ListNode *ptr2 = head;
        ListNode *ptr = NULL;
        while(head!=last){
            ptr = head;
            head = head->next;
            ptr->next = prev;
            prev = ptr;
        }
        return {prev, ptr2};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        ListNode *ptr = head;
        ListNode *prevHead = head;
        while(ptr){
            ListNode *ptr2 = ptr;
            int x = k;
            while(ptr2 && x--){
                ptr2 = ptr2->next;
            }

            vector<ListNode*> t(2);

            if(x>0)
                break;
            else
                t = reverse(ptr, ptr2, ptr2);

            cout<<t[0]->val<<' '<<t[1]->val<<' ';
            if(t[1]->next)
                cout<<t[1]->next->val<<endl;
            if(head==prevHead)
                head = t[0];
            else
                prevHead->next = t[0];
            prevHead = t[1];
            ptr = ptr2;
        }
        return head;
    }
};