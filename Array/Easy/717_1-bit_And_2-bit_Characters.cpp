class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //Greedy Approach
        int i = 0;
        int n = bits.size();
        while (i < n - 1) {       // stop before the last bit
            if (bits[i] == 1) {
                i += 2;           // take 2-bit character
            } else {
                i += 1;           // take 1-bit character
            }
        }
        return i == n - 1;        // true if stopped at last bit
    }
};
