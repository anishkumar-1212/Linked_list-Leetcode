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

        // Count total nodes
        int count = 0;
        ListNode* temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }

        // Dummy node
        ListNode dummy(0);
        dummy.next = head;

        // groupPrev always points to the node before current group
        ListNode* groupPrev = &dummy;

        while (count >= k) {

            // First node of current group
            ListNode* curr = groupPrev->next;

            // Node after current group
            ListNode* next = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = groupPrev->next;
                groupPrev->next = next;
                next = curr->next;
            }

            // Move groupPrev to the end of reversed group
            groupPrev = curr;

            count -= k;
        }

        return dummy.next;
    }
};