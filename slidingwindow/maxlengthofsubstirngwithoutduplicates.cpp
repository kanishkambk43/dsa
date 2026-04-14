/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>hash(256,-1);
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<s.length()){
            int length;
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
                length=r-l+1;
                maxlen=max(length,maxlen);
            
            hash[s[r]]=r;
            r++;
        }
       return maxlen;
    }
};
