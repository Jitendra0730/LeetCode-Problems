class Solution {
public:
    long long mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (left >= right) return 0;

        int mid = (left + right) / 2;
        long long count = mergeSort(prefix, left, mid, lower, upper)
                        + mergeSort(prefix, mid + 1, right, lower, upper);

        int l = mid + 1, r = mid + 1;

        // Count valid ranges
        for (int i = left; i <= mid; i++) {
            while (l <= right && prefix[l] - prefix[i] < lower) l++;
            while (r <= right && prefix[r] - prefix[i] <= upper) r++;
            count += (r - l);
        }

        // Merge step (sorted order)
        vector<long long> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (prefix[i] < prefix[j]) temp.push_back(prefix[i++]);
            else temp.push_back(prefix[j++]);
        }
        while (i <= mid) temp.push_back(prefix[i++]);
        while (j <= right) temp.push_back(prefix[j++]);

        for (int i = 0; i < temp.size(); i++)
            prefix[left + i] = temp[i];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return (int)mergeSort(prefix, 0, n, lower, upper);
    }
};
