class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int k = n / 4;
        //Sliding Window Approach
        for (int i = 0; i + k < n; i++) {
            if (arr[i] == arr[i + k]) return arr[i];
        }
        return -1;
    }
};
