/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        if(nums.size()==1){// if there is only one single element 
            return nums[0];
        }
        if(nums[0]!=nums[1]){// if the first element is single 
            return nums[0];
        }
        if(nums[n]!=nums[n-1]){// if the last element is single 
            return nums[n];
        }
        int low=1;
        int high=n-1;
        while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];// somehow the mid reaches the target
        }
        if((mid%2==1) &&(nums[mid]==nums[mid-1])|| (mid%2==0) && (nums[mid]==nums[mid+1])){
            low=mid+1;// if the pair index is (even,odd) : the target is present in the right half so we eliminate the right half ;
        }
        else {
            high=mid-1;// if the pair index is (odd,even) : the target is present in the left half so we eliminate the left half ;
        }
    }
    return -1;// if no element is single ;
    }
};