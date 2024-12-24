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
        ListNode* preheadLess = new ListNode;
        ListNode* preheadMore = new ListNode;
        ListNode* tailLess = new ListNode;
        ListNode* tailMore = new ListNode;
        while(head != nullptr){
            if(head->val < x){
                tailLess->next = head;
                head=head->next;
                tailLess=tailLess->next;
                tailLess->next = nullptr;
                if(preheadLess->next == nullptr)    preheadLess->next=tailLess;
            }
            else{
                tailMore->next = head;
                head=head->next;
                tailMore=tailMore->next;
                tailMore->next = nullptr;
                if(preheadMore->next == nullptr)    preheadMore->next=tailMore;
            }
        }
        if(preheadLess->next == nullptr) return preheadMore->next;
        tailLess->next = preheadMore->next;
        return preheadLess->next;
    }
};