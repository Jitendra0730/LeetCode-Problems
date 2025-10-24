class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long ans = 0, pow2 = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans + (nums[i] * pow2) % MOD) % MOD;
            ans = (ans - (nums[n-1-i] * pow2) % MOD + MOD) % MOD;
            pow2 = (pow2 * 2) % MOD;
        }
        return ans;
    }
};
