class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        while(insertPos < nums.size()) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};
