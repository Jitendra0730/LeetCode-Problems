class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int mxCount = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==1) count++;
            else {
                mxCount = max(mxCount, count);
                count = 0;
            }
        }
        mxCount = max(mxCount, count);
        return mxCount;
    }
};
