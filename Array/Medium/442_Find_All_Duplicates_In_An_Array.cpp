class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int i = 0;
        while(i < nums.size()) {
            int correct = nums[i] - 1;
            if(nums[i] != nums[correct])
                swap(nums[i], nums[correct]);
            else
                i++;
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i+1)
                result.push_back(nums[i]);
        }
        return result;
    }
};
