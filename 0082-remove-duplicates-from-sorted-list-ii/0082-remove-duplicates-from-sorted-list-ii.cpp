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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prevUnique = dummy;
        ListNode* cur = head;
        int lastVal = -1000;

        while (cur != nullptr){
            if(cur != nullptr && cur->next != nullptr && cur->val == cur->next->val){
                prevUnique->next = cur->next->next;
                lastVal = cur->val;
                cur = prevUnique->next;
            }
            else if(cur->val == lastVal){
                prevUnique->next = cur->next;
                cur=cur->next;
            }
            else{
                cur=cur->next;
                prevUnique=prevUnique->next;
                lastVal = prevUnique->val;
            }
        }
        return dummy->next;
    }
};