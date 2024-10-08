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
        // copy each node
        Node * ptr = head;
        while(ptr){
            Node * t = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = t;
            ptr = ptr->next->next;
        }
        ptr = head;
        while(ptr){
            cout<<ptr->val<<' ';
            ptr = ptr->next;
        }


        // Copy Random Pointers
        ptr = head;
        // cout<<endl;
        while(ptr){
            // cout<<ptr->val<<' ';
            if(ptr->random)
                ptr->next->random = ptr->random->next;
            else
                ptr->next->random = NULL;
            ptr = ptr->next->next;
        }
        // ptr = head;
        // while(ptr){
        //     cout<<ptr->val<<' ';
        //     ptr = ptr->next;
        // }

        // Seprate two LL
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