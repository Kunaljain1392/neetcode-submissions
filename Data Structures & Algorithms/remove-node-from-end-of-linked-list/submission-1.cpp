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
        // two pointer approach 
        // first pointer ko dummy se n+1 nodes aage tk chlo 
        // second pointer ko dummy se ab next krte rho jb tk first null na ho jaye
        // second ki next node hi delete krni hai 
        if(head == NULL) {
            return head;
        } 
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        int cnt = 0;
        while(cnt <= n) {
            first = first->next;
            cnt++;
        }
        while(first!=NULL) {
            first = first->next;
            second = second->next;
        }
        ListNode* del = second->next;
        second->next = second->next->next;
        delete(del);
        return dummy->next;

    }
};
