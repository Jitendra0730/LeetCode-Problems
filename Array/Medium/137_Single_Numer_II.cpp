class Solution {
public:
    int singleNumber(vector<int>& nums) {
      //Bitwise State Machine Approach (Optimised Space)
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};
