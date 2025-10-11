class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        bitset<10001> bits(1);  // initially sum 0 is reachable
        for (int num : nums)
            bits |= (bits << num);  // shift bits to add new possible sums

        return bits[target];
    }
};
