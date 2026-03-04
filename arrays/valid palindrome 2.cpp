/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true*/

class Solution {
public:
bool palindrome(int i,int j,string s){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return palindrome(i+1,j,s)||palindrome(i,j-1,s);
            }
                i++;
                j--;
            }
            return true;
        }
};