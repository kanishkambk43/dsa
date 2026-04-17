/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
     struct ListNode* temp=head;
     struct ListNode* prev=NULL;
     struct ListNode* front;
       while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
       }
       return  prev;
}