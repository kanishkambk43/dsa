/*There is only one repeated number in nums, return this repeated number.*/
/*Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     unordered_map<int, int> mp;
     int n=nums.size();
    for(int i=0;i<n;i++){
        if(mp[nums[i]]==1){
            return nums[i];
        }
        mp[nums[i]]++;
    }
    return 0;
        
    }
};