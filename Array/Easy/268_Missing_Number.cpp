class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = n;
        int l = 0, r = n-1;
        while(l<=r) {
            int mid = l + (r - l)/2;
            if(nums[mid] > mid) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
