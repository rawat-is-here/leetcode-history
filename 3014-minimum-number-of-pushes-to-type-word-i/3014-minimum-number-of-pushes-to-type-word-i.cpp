class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int q = n / 8;
        int r = n % 8;

        // Sum of pushes for full groups of 8 + remaining letters
        return 4 * q * (q + 1) + r * (q + 1);
    }
};