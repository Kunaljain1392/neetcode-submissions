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
private:
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare > pq;

        // phele list ka head  heap me push krenge 

        for(int i=0;i<lists.size();i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummyHead = NULL;
        ListNode* dummyTail = dummyHead;
        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            if(dummyHead == NULL) {
                dummyHead = curr;
                dummyTail = curr;
            } else {
                dummyTail->next = curr;
                dummyTail = dummyTail->next;
            }
            if(curr->next != NULL) {
                pq.push(curr->next);
            }

        }

        return dummyHead;

    }
};
