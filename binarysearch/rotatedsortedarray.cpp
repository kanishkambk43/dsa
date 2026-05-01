/*Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[low]){// to find sorted part 
                if(nums[low]<=target&&nums[mid]>=target){//finding the element in the letft sorted part
                    high=mid-1;
                }
                else{ 
                    low=mid+1;
                }
            }
            else{// if left is not sorted then it is a must right should be sorted
                if(nums[mid]<=target&& nums[high]>=target){//finding the element if it is present in the left of right sorted 
                    low=mid+1;
                }
                else{// finding the element if it is present in the right of right sorted .
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};