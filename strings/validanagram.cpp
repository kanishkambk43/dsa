/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false*/

class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length()!=t.length())return false;
       vector<int>vec(26,0);
       int i=0;
       while(i<s.length()){
        vec[s[i]-'a']++;
        vec[t[i]-'a']--;
        i++;
       }
       for(i=0;i<26;i++){
        if(vec[i]!=0)return false;
       }
       return true;
    }
};