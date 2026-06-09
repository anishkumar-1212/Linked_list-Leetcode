class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        // Find beforeLeft
        ListNode* beforeLeft = &dummy;

        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* leftNode = beforeLeft->next;

        // Find rightNode
        ListNode* rightNode = leftNode;

        for (int i = left; i < right; i++) {
            rightNode = rightNode->next;
        }

        ListNode* afterRight = rightNode->next;

        // CUT
        beforeLeft->next = nullptr;
        rightNode->next = nullptr;

        // REVERSE NORMALLY
        ListNode* prev = nullptr;
        ListNode* curr = leftNode;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // RECONNECT
        beforeLeft->next = prev;
        leftNode->next = afterRight;

        return dummy.next;
    }
};