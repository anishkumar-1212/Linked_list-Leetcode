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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        sort(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int x : nums) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy->next;
    }
};