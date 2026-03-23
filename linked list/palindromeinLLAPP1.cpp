/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/
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
    vector<int>vec;
    while(head!=NULL){
        vec.push_back(head->val);
        head=head->next;
    }
    int i=0;
    int j=vec.size()-1;
    while(i<j){
    if(vec[i]!=vec[j]){
        return false;
    }
    i++;
    j--;}
    return true;

    }
};