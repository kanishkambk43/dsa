/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i;
        int hash[3]={-1,-1,-1};
        int count=0;
        for(i=0;i<s.length();i++){
            hash[s[i]-'a']=i;
            count=count+1+(min(hash[0],min(hash[1],hash[2])));
        }
        return count;
    }
};