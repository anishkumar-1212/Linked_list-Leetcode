/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Outer loop: Iterate through each node of list A
        ListNode* tempA = headA;
        while (tempA != nullptr) {
            
            // Inner loop: Check against every node of list B
            ListNode* tempB = headB;
            while (tempB != nullptr) {
                
                // Compare memory addresses, not node values
                if (tempA == tempB) {
                    return tempA; 
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        
        // Return nullptr if no intersection exists
        return nullptr;
    }
};
