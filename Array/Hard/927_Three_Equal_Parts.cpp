class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int total = count(arr.begin(), arr.end(), 1);
        int n = arr.size();
        if (total == 0) return {0, n - 1};
        if (total % 3 != 0) return {-1, -1};
        
        int k = total / 3;
        int first = -1, second = -1, third = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                cnt++;
                if (cnt == 1) first = i;
                else if (cnt == k + 1) second = i;
                else if (cnt == 2*k + 1) third = i;
            }
        }

        while (third < n) {
            if (arr[first] != arr[second] || arr[second] != arr[third])
                return {-1, -1};
            first++; second++; third++;
        }
        return {first - 1, second};
    }
};
