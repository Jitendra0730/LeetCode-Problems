class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int flip = 0, ans = 0;

        for (int i = 0; i < n; ++i) {
            flip ^= diff[i]; // update flip status
            if ((nums[i] ^ flip) == 0) { // we see an effective 0
                if (i + k > n) return -1; // cannot flip beyond array
                ans++;
                flip ^= 1; // toggle flip state
                diff[i + k] ^= 1; // flip effect ends after k elements
            }
        }
        return ans;
    }
};
