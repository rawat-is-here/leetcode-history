/* only written for streeak purpose, IDK anything about it*/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // nums[i] <= 1500, so every XOR result is below 2048.
        const int MAX_XOR = 2048;

        vector<bool> pairXor(MAX_XOR, false);
        vector<bool> tripletXor(MAX_XOR, false);

        // Store all possible XOR values of two elements.
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }

        // Combine every possible pair XOR with a third element.
        for (int value = 0; value < MAX_XOR; value++) {
            if (!pairXor[value]) {
                continue;
            }

            for (int num : nums) {
                tripletXor[value ^ num] = true;
            }
        }

        int uniqueValues = 0;

        for (bool exists : tripletXor) {
            if (exists) {
                uniqueValues++;
            }
        }

        return uniqueValues;
    }
};