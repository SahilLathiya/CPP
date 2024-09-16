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
    ListNode * reverse(ListNode *head, ListNode *last, ListNode *prev){
        ListNode * temp = NULL;
        while(head!=last){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        ListNode *ptr = head;
        ListNode *prev = NULL;
        ListNode *prevGroupTail = NULL;
        ListNode *newHead = NULL;
        int cnt = 0;

        while (ptr) {
            ListNode *groupHead = ptr;
            cnt = 0;
            
            // Check if there are enough nodes left in the list to reverse
            while (ptr && cnt < k) {
                ptr = ptr->next;
                cnt++;
            }

            if (cnt == k) {
                // Reverse the current group
                ListNode *reversedGroupHead = reverse(groupHead, ptr, ptr);
                
                // If this is the first group, update the new head of the list
                if (!newHead) {
                    newHead = reversedGroupHead;
                }
                
                // Connect the previous group's tail to the current group's head
                if (prevGroupTail) {
                    prevGroupTail->next = reversedGroupHead;
                }
                
                // The old head of this group becomes the tail after reversal
                prevGroupTail = groupHead;
            } else {
                // If there are fewer than k nodes left, no reversal; just connect the tail
                if (prevGroupTail) {
                    prevGroupTail->next = groupHead;
                }
            }
        }

        return newHead ? newHead : head;
    }
};