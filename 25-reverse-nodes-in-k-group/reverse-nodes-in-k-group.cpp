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
    ListNode* reverse(ListNode* head, int k){
        ListNode *prev = NULL;
        ListNode *ptr = NULL;
        while(head && k--){
            ptr = head;
            head = head->next;
            ptr->next = prev;
            prev = ptr;
        }
        if(k){
            head = prev;
            while(head){
                ptr = head;
                head = head->next;
                ptr->next = prev;
                prev = ptr;
            }
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr = head;
        while(ptr){
            ListNode *ptr2 = ptr;
            int arr[k];
            int x = k;
            while(ptr && x--){
                arr[k-1-x] = ptr->val;
                ptr = ptr->next;
            }
            if(ptr==NULL && x>0)
                break;
            x = k;
            while(x--){
                ptr2->val = arr[x];
                ptr2 = ptr2->next;
                // cout<<arr[x]<<' ';
            }
        }
        return head;
    }
};