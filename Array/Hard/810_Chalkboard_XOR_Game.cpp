class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int num : nums)
            x ^= num;

        int n = nums.size();
        return x == 0 || n % 2 == 0;
    }
};
