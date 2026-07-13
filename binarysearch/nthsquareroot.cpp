/*You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
Constraints:
1 ≤ n ≤ 9
0 ≤ m ≤ 20*/



class Solution {
  public:
    int limitchecker(int mid,int n,int limit){
            long long ans=1;
            for(int i=1;i<=n;i++){
                ans=ans*mid;
                if(ans>limit)return 1;}
                if(ans==limit)return 2;
                return 0;
                
            }
    int nthRoot(int n, int m) {
        // Code here
      
            if(m==0){
                return 0;
            }
        int low=1;
        int high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cu=limitchecker(mid,n,m);
            if(cu==2){
                return mid;
            }
            else if(cu==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};