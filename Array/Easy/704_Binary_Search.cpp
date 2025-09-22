class Solution {
public:
    //Helper Function
    int binSearch(vector<int> arr, int tar, int st, int end) {
        if(st <= end) {
            int mid = (st+end)/2;

            if (arr[mid] == tar) return mid;
            if(arr[mid] <= tar) {
                return binSearch(arr, tar, mid+1, end);
            } else {
                return binSearch(arr, tar, st, mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size()-1);
    }
};
