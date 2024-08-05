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
    ListNode* insetAtHead(ListNode* head, int a){
        ListNode *ptr = new ListNode(a);
        ptr->next = head;
        head = ptr;
        return head;
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
        while(c--){
            ptr = ptr->next;
        }

        int arr[k];
        int i = 0;
        while(ptr){
            arr[i] = ptr->val;
            i++;
            ptr = ptr->next;
        }

        for(int z=k-1;z>=0;z--){
            head = insetAtHead(head, arr[z]);
        }
        ptr = head;
        while(--len){
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};