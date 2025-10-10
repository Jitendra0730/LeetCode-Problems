class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int num : nums)
            xorAll ^= num;

        // Get rightmost set bit
        long long diffBit = xorAll & (-xorAll);

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & diffBit)
                a ^= num;   // group with set bit
            else
                b ^= num;   // group with unset bit
        }

        return {a, b};
    }
};
