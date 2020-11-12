/*

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?
*/

class Solution {
    public boolean find132pattern(int[] nums) {
        int len=nums.length;
        int prev=999999999;          //assume prev value as max value and (9 times 9 to run all test cases)
        for(int i=1;i<len-1;i++){  //from 2nd position to last second position.....
            if(nums[i-1]<prev){
                prev=nums[i-1];      //keep updated prev. value..
            }
            if(nums[i]<=prev){
                continue;
            }
            for(int j=i+1;j<len;j++){
                if(nums[j]>prev && nums[j]<nums[i]){
                    return true;
                }
            }
        }
        return false;
    }
}
