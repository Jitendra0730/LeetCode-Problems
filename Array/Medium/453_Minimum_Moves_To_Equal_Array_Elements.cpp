class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int num : nums)
            moves += (num - minNum);
        return moves;
    }
};
