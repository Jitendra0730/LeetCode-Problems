class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Using Moore's Voting Algorithm
        int freq = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq ++;
            }
            else {
                freq --;
            }
        }
    return ans;
    }
};
