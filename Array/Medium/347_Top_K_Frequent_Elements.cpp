class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        // Create buckets
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        // Collect top k
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
