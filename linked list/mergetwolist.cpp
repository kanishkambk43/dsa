/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 */

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode dummy;
        ListNode *temp=&dummy;
        ListNode *te=temp;
        while(temp1!=nullptr && temp2!=nullptr){
           if(temp1->val<=temp2->val){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
           }
           else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
           }   
        }  
         if(temp1!=nullptr){
            while(temp1!=nullptr){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }}
        else{
            while(temp2!=nullptr){
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        return te->next;
         }      
            };