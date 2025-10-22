class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);

        for (int i = 0; i < n; i++) {
            int low = (i - nums[i] + 1 + n) % n;
            int high = (i + 1) % n;

            change[low]--;
            change[high]++;
            if (low > high) change[0]--;
        }

        int bestK = 0, maxScore = -n, score = 0;
        for (int k = 0; k < n; k++) {
            score += change[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        return bestK;
    }
};
