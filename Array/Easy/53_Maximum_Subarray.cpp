class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int currMax = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currMax = max(nums[i], nums[i] + currMax);
            maxSoFar = max(currMax, maxSoFar);
        }
        return maxSoFar;
    }
};
