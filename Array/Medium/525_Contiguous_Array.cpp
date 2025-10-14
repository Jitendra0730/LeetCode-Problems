class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> firstIndex(2*n + 1, -2); // shift by n for negative sums
        int sum = 0, maxLen = 0;
        firstIndex[n] = -1; // prefix sum = 0 before start

        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            int index = sum + n;
            if (firstIndex[index] != -2)
                maxLen = max(maxLen, i - firstIndex[index]);
            else
                firstIndex[index] = i;
        }
        return maxLen;
    }
};
