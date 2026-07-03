/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vec;
        deque<int>dq;
        for(int i=0;i<n;i++){
            while(!dq.empty()&&dq.front()<=i-k){//checking the front is present in the window boundary 
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){//removing the end elements if they are smaller than the current element 
                dq.pop_back();
            }
            dq.push_back(i);// keeping the currentelement if it is smaller also 
            if(i>=k-1){// this condition is for the initial stage if the Window of size k is formed
                vec.push_back(nums[dq.front()]);
            }
            
        }
        return vec;}};