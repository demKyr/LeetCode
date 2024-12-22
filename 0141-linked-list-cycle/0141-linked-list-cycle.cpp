/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        cout<<head;
        if(head == NULL) return false;
        ListNode *temp = head;
        int cnt = 0;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
            if(cnt > 10000)
                return true;
        }
        return false;
    }
};