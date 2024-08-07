/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * ptr = head;
        while(ptr){
            Node * temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = ptr->next->next;
        }
        
        ptr = head;
        while(ptr){
            if(ptr->random)
                ptr->next->random = ptr->random->next;
            else
                ptr->next->random = NULL;
            ptr = ptr->next->next;
        }

        ptr = head;
        Node * ans = new Node(0);
        Node * t = ans;
        while(ptr){
            ans->next = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            ans = ans->next;
        }
        return t->next;
    }
};