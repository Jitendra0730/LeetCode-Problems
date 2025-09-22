class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1, smax = -1, maxIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(max < nums[i]) {
                smax = max;
                max = nums[i];
                maxIdx = i;
            } else if( smax < nums[i]) {
                smax = nums[i];
            }
        }
        if(smax*2 <= max){
            return maxIdx;
        } else return -1;
    }
};
