/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
example 1 :
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy; 
   
    dummy.next=head;
    struct ListNode* l=head;
    int j=0;
    while(l!=NULL){
        j++;
        l=l->next;
    }
    int targetprev=j-n;//it is for the prev pointer 
    struct ListNode* temp=head;
    struct ListNode* prev=&dummy;
    
    while(targetprev){
       targetprev--;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return dummy.next;


}