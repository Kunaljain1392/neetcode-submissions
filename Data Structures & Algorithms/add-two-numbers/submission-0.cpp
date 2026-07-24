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

        // APP-1 :-

        // ListNode* h1 = l1;
        // ListNode* h2 = l2;
        // int c = 0;
        // ListNode* dummy = new ListNode(-1) ;
        // ListNode* dummyTail = dummy;

        // while(h1 != NULL && h2 != NULL) {
        //     int val = h1->val + h2->val + c;
        //     c = val/10;
        //     int n = val%10;
        //     ListNode* temp = new ListNode(n);
        //     dummyTail->next = temp;
        //     dummyTail = dummyTail->next;
        //     h1 = h1->next;
        //     h2 = h2->next;
        // }
        // while(h1 == NULL && h2 != NULL) {
        //     int val = h2->val + c;
        //     c = val/10;
        //     int n = val%10;
        //     ListNode* temp = new ListNode(n);
        //     dummyTail->next = temp;
        //     dummyTail = dummyTail->next;
        //     h2 = h2->next;
        // }
        // while(h2 == NULL && h1 != NULL) {
        //     int val = h1->val + c;
        //     c = val/10;
        //     int n = val%10;
        //     ListNode* temp = new ListNode(n);
        //     dummyTail->next = temp;
        //     dummyTail = dummyTail->next;
        //     h1 = h1->next;
        // }
        // if(h1 == NULL && h2 == NULL && c != 0) {
        //     ListNode* temp = new ListNode(c);
        //     dummyTail->next = temp;
        //     dummyTail = dummyTail->next;
        // }
        // return dummy->next;

        //  APP-2 :-
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        int c = 0;
        ListNode* dummy = new ListNode(-1) ;
        ListNode* dummyTail = dummy;

        while(h1 != NULL || h2 != NULL || c != 0) {
            int val1 = 0;
            if(h1 != NULL) {
                val1 = h1->val;
                h1 = h1->next;
            }
            int val2 = 0;
            if(h2 != NULL) {
                val2 = h2->val;
                h2 = h2->next;
            }

            int n = val1 + val2 + c;
            c = n/10;
            n = n%10;

            ListNode* temp = new ListNode(n);
            dummyTail->next = temp;
            dummyTail = dummyTail->next;
        }
    return dummy->next;

    }
};
