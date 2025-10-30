class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        
        // Build max reach from each start
        for (int i = 0; i <= n; ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            maxReach[start] = max(maxReach[start], end);
        }

        int taps = 0;
        int currEnd = 0, farthest = 0;

        for (int i = 0; i <= n; ++i) {
            if (i > farthest) return -1;  // uncovered gap
            farthest = max(farthest, maxReach[i]);
            if (i == currEnd) {            // need new tap
                taps++;
                currEnd = farthest;
                if (currEnd >= n) return taps;
            }
        }

        return -1;
    }
};
