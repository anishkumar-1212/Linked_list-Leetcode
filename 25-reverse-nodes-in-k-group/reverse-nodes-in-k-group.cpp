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

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (count >= k) {

            // First node of current group
            ListNode* groupHead = groupPrev->next;

            // Reverse exactly k nodes
            ListNode* prev = nullptr;
            ListNode* curr = groupHead;

            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous part to new head
            groupPrev->next = prev;

            // Connect tail of reversed group to remaining list
            groupHead->next = curr;

            // Move groupPrev to tail of current reversed group
            groupPrev = groupHead;

            count -= k;
        }

        return dummy.next;
    }
};