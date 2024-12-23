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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0) return head->next;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        if(cnt==1 || cnt-n == 0) return head->next;
        // if(cnt-n == 0) return head->next;
        temp = head;
        for(int i=1;i<cnt-n;i++)
            temp = temp->next;
        if(temp->next != nullptr)
            temp->next=temp->next->next;
        else
            temp->next=nullptr;
        return head;
    }
};