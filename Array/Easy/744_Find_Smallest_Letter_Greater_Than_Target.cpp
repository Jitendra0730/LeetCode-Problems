class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        //Binary Search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid - 1;  // search left half
            } else {
                left = mid + 1;   // search right half
            }
        }
        return letters[left % letters.size()];  // wrap around 
    }
};
