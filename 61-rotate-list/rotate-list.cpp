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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if (k == 0)
            return head;

        while (k--) {

            ListNode* prev = nullptr;
            ListNode* curr = head;

            // Reach last node
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            // Move last node to front
            prev->next = nullptr;
            curr->next = head;
            head = curr;
        }

        return head;
    }
};