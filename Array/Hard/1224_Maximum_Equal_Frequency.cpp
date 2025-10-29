class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int N = nums.size();
        // value range assumed <= 100000 per constraints
        const int VAL_MAX = 100000;
        vector<int> freq(VAL_MAX + 1, 0);
        // count[f] = number of values that currently appear exactly f times
        // max frequency cannot exceed N, so size N+2 is safe
        vector<int> count(N + 2, 0);

        int maxFreq = 0;
        int distinct = 0; // number of distinct values seen so far
        int res = 0;

        for (int i = 0; i < N; ++i) {
            int x = nums[i];

            if (freq[x] > 0) {
                count[freq[x]]--;         // remove old frequency bucket
            } else {
                distinct++;               // new distinct value
            }

            freq[x]++;
            count[freq[x]]++;             // add to new frequency bucket
            maxFreq = max(maxFreq, freq[x]);

            int len = i + 1;
            bool ok = false;

            // Case 1: all numbers appear exactly once
            if (maxFreq == 1) {
                ok = true;
            }
            // Case 2: one number has frequency 1 and all others have frequency maxFreq
            // i.e., count[1] == 1 and remaining elements form maxFreq * (distinct - 1)
            else if (count[1] == 1 && (count[maxFreq] * maxFreq + 1 == len)) {
                ok = true;
            }
            // Case 3: one number has frequency maxFreq and all others have frequency maxFreq-1
            // i.e., count[maxFreq] == 1 and maxFreq + (maxFreq-1) * (distinct - 1) == len
            else if (count[maxFreq] == 1 && (count[maxFreq] * maxFreq + (count[maxFreq - 1] * (maxFreq - 1)) == len)) {
                ok = true;
            }

            if (ok) res = len;
        }

        return res;
    }
};
