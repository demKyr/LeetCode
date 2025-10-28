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
    ListNode* partition(ListNode* head, int x) {
        ListNode* preheadLess = new ListNode(0);
        ListNode* preheadMore = new ListNode(0);
        ListNode* tailLess = preheadLess;
        ListNode* tailMore = preheadMore;
        while (head != nullptr) {
            if (head->val < x) {
                tailLess->next = head;
                tailLess = tailLess->next; 
            } else {
                tailMore->next = head;
                tailMore = tailMore->next;
            }
            head = head->next;
        }
        tailMore->next = nullptr; 
        tailLess->next = preheadMore->next; 
        ListNode* returnHead = preheadLess->next;
        delete preheadLess;
        delete preheadMore;
        return returnHead;
    }
};