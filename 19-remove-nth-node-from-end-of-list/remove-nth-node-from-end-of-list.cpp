class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // Move both pointers
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Delete node
        ListNode* toDelete = slow->next;

        slow->next = slow->next->next;

        delete toDelete;

        return dummy.next;
    }
};