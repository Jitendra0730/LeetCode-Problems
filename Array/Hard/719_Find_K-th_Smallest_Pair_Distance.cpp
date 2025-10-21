class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int mid = (low + high) / 2;

            // Count pairs with distance <= mid
            int count = 0, left = 0;
            for (int right = 0; right < n; right++) {
                while (nums[right] - nums[left] > mid)
                    left++;
                count += right - left;
            }

            if (count >= k) 
                high = mid;
            else 
                low = mid + 1;
        }
        return low;
    }
};
