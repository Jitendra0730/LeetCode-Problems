class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int MAX = 1 << 16; // 65536
        vector<int> freq(MAX, 0);

        // Step 1: Count all pairwise AND results
        for (int a : nums)
            for (int b : nums)
                freq[a & b]++;

        // Step 2: Count valid triples
        int count = 0;
        for (int c : nums) {
            for (int val = 0; val < MAX; ++val) {
                if ((val & c) == 0)
                    count += freq[val];
            }
        }
        return count;
    }
};
