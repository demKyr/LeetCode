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
        if(head == nullptr) return nullptr;
        map<Node*,Node*> map;
        Node* newHead = new Node( head->val);
        Node* newTemp = newHead;
        Node* temp = head->next;
        map[head] = newHead;
        while(temp != nullptr){
            newTemp->next = new Node(temp->val);
            map[temp] = newTemp->next;
            temp = temp->next;
            newTemp = newTemp->next;
        }

        temp = head;
        newTemp = newHead;
        while(temp != nullptr){
            newTemp->random = map[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }

        return newHead;
    }
};