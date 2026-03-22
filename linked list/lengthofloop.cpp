/*Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.
*/
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node * slow=head;
        Node * fast =head;
        int count=0;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                count=1;
                Node * temp=slow->next;
                while(temp!=slow){
                    temp=temp->next;
                    count++;
                }
                return count;
            }
        }
         return count;
        
    }
};