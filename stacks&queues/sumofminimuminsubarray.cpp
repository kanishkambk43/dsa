/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        vector<int>left(n),right(n);
        //in the left and right array we are not storing the indexes instead we are storing the contribution of each element ;
        //contribution using nse
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //contribution using pse 
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        int mod=(1e9+7);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long contribution=1LL*left[i]*right[i]*arr[i];
            ans=(ans+contribution)%mod;
        }
        return (int)ans;
    }
};