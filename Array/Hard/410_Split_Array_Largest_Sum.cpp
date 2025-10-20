class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int cnt = 1, curr = 0;
        for (int num : nums) {
            if (curr + num > maxSum) {
                cnt++;
                curr = num;
                if (cnt > k) return false;
            } else {
                curr += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
