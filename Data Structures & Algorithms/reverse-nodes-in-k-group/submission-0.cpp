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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        int cnt=0;

        // count nodes
        int nodeCount = 0;
        ListNode* dummy = head;
        while(dummy != NULL && nodeCount < k) {
            dummy = dummy->next;
            nodeCount++;
        }

        if(nodeCount < k) {
            return head;
        }

        while(temp != NULL && cnt < k) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            cnt++;
        }

        if(temp != NULL) {
            head->next = reverseKGroup(temp,k);
        }

        return prev;

    }
};
