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
    int lengthOfLL(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* removeNthNode(ListNode* head, int n){
        if(head==NULL)
            return head;

        ListNode* ptr = head;
        ListNode* prev = NULL;
        int cnt = 0;
        while(cnt<n){
            cnt++;
            prev = ptr;
            ptr = ptr->next;
        }
        if(prev){
            cout<<ptr->val<<' ';
            prev->next = ptr->next;
        }
        else{
            // cout<<"TTT";
            // ptr = head;
            // while(ptr->next!=NULL){
            //     prev = ptr;
            //     ptr = ptr->next;
            //     cout<<"werwe";
            // }
            // prev->next = NULL;
            return head->next;
        }

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lengthOfLL(head);
        if(len==1 && n>=1)
            return NULL;
        head = removeNthNode(head, len - n);
        return head;
    }
};