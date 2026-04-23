/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
       }
       
       ListNode* newhead=reverse(slow->next);
       ListNode* forreversing=newhead;
       ListNode* temp=head;
       while(newhead!=nullptr){
        if(newhead->val!=temp->val){
            reverse(forreversing);
            return false;
        }
        newhead=newhead->next;
        temp=temp->next;
       }
       return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode dummy;
        dummy.next=head;
        ListNode *prev=nullptr;
        ListNode* temp=head;
        ListNode* front;
        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};