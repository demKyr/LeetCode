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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt=1;
        while(head->next != nullptr){
            cnt++;
            head = head->next;
        }

        if(k%cnt == 0) {
            ListNode *returnHead = dummy->next;
            delete dummy;
            return returnHead;
        }

        head->next = dummy->next;   // last element points to first
        head = dummy->next;         // reinitialise head
        for(int i=0;i<cnt-(k%cnt)-1;i++)
            head = head->next;
        dummy->next = head->next;   // dummy points to new last element
        head->next = nullptr;       // new last element points to null

        ListNode *returnHead = dummy->next;
        delete dummy;
        return returnHead;
    }
};