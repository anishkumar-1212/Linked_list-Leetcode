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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //finding the middle 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        
        //reversing the second half 
        ListNode* curr=slow;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr!=NULL){
            next=curr->next;  //save the link 
            curr->next=prev; //Atttacked it to the backward
            prev=curr; //updating the prev node
            curr=next; // updating the current node 
        }
    
        //for comparision

        ListNode* first=head;
        ListNode* second=prev;

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};