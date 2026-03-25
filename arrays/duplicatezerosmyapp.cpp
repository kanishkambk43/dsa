/*Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 */

 class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<n){
            if(arr[i]==0){
                for(int j=n-1;j>=i+1;j--){
                    arr[j]=arr[j-1];
                }
                if(i+1<n){
                arr[i+1]=0;
                i=i+2;}
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
    }
};