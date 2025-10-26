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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0); 
        ListNode *temp = dummy;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 == nullptr){
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else if(l2 == nullptr){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                if(l1->val <= l2->val){
                    temp->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else{
                    temp->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            temp = temp->next;
        }
        ListNode *resultHead = dummy->next; 
        delete dummy;
        return resultHead;
    }
};