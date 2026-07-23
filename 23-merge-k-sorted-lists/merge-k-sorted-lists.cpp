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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        // Store all values
        for (ListNode* head : lists) {
            while (head) {
                values.push_back(head->val);
                head = head->next;
            }
        }

        // Sort all values
        sort(values.begin(), values.end());

        // Create new linked list
        ListNode dummy(0);
        ListNode* temp = &dummy;

        for (int x : values) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy.next;
    }
};