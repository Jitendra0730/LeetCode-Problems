class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        //Binary Search TC = O(log n)
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than the rightmost one,
            // the min must be in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Else the min lies in the left half (including mid)
            else {
                right = mid;
            }
        }

        // When loop ends, left == right -> min element
        return nums[left];
    }
};
