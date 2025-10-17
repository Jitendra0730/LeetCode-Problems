class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum lies in right half
                left = mid + 1;
            } 
            else if (nums[mid] < nums[right]) {
                // Minimum lies in left half
                right = mid;
            } 
            else {
                // nums[mid] == nums[right] → duplicates, shrink range
                right--;
            }
        }
        return nums[left];
    }
};
