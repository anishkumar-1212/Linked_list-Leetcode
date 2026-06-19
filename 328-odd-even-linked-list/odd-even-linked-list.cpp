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
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* evenHead = evenNode;

        while (evenNode && evenNode->next) {

            // connect odd nodes
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;

            // connect even nodes
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }

        // attach even list after odd list
        oddNode->next = evenHead;

        return head;
    }
};