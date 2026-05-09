/*Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.*/


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0;
        int high=arr.size()-1;
        int mini=INT_MAX;
        int indx;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[mid]){
                if(arr[low]<mini){
                indx=low;
                mini=arr[low];}
                low=mid+1;
            }
            else{
                if(arr[mid]<mini){
                indx=mid;
                mini=arr[mid];}
                high=mid-1;
            }
        }
        return indx;
    }
};