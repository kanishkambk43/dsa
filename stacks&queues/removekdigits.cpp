/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string str="";
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&k>0&&st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){// if the k is not zero
            st.pop();
            k--;
        }
        if(st.empty()){// k=nums.size()
            return "0";
        }
        while(!st.empty()){// stack to string 
            str+=st.top();
            st.pop();
        }
        
        while(!str.empty()&&str.back()=='0'){//removing leading zeros but string is in reverse order 
            str.pop_back();
        }
        if(str.empty()){// if the string only contained zeros after ex(01000)
            return "0";
        }
        reverse(str.begin(),str.end());//reversing the string will get us a proper order
        return str;

    }
};