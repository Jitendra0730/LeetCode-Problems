class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        int n = d.size();
        for (int i = 3; i < n; i++) {
            // Case 1: crosses 3rd line before
            if (d[i] >= d[i-2] && d[i-1] <= d[i-3]) return true;

            // Case 2: touches 4th line before
            if (i >= 4 && d[i-1] == d[i-3] && d[i] + d[i-4] >= d[i-2])
                return true;

            // Case 3: crosses 5th line before
            if (i >= 5 && d[i-2] > d[i-4] &&
                d[i-1] <= d[i-3] &&
                d[i-1] + d[i-5] >= d[i-3] &&
                d[i] + d[i-4] >= d[i-2])
                return true;
        }
        return false;
    }
};
