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
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

    void mergeAlternately(ListNode* head1, ListNode* head2) {
        while(head1 != NULL && head2 != NULL) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;
            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }

    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
        return;

        ListNode* s = head;
        ListNode* h = head;

        while(h != NULL && h->next != NULL) {
            s = s->next;
            h = h->next->next;
        }

        ListNode* head2 = rev(s->next);
        s->next = NULL;
        ListNode* head1 = head;

        mergeAlternately(head1,head2);
        

    }
};
