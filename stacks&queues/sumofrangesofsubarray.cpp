/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 */

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n),right(n),l(n),r(n);
        stack<int>st;
        //finding contribution using nse
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
        while(!st.empty())st.pop();
        //finding contribution using pse
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
        while(!st.empty())st.pop();
        //finding contributions using nge
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                r[i]=n-i;
            }
            else{
                r[i]=st.top()-i;
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        //finding contribution of every element using pge
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                l[i]=i+1;
            }
            else{
                l[i]=i-st.top();
            }
            st.push(i);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long mini=0;
            long long maxi=0;
            mini=(mini+1LL*left[i]*right[i]*arr[i]);
            maxi=(maxi+1LL*l[i]*r[i]*arr[i]);
            sum=sum+(maxi-mini);
        }
        return sum;
    }
};