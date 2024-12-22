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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0; 
        ListNode *dummy = new ListNode(0); 
        ListNode *temp = dummy;
        
        while (l1 != nullptr || l2 != nullptr || c != 0) {
            int sum = c; 
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            c = sum / 10; 
            temp->next = new ListNode(sum % 10); 
            temp = temp->next;
        }
        
        return dummy->next; 
    }
};