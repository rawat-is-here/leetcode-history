class Solution {
public:
    int reverse(int x) {
        int r = 0, num = 0;
        while (x != 0) {
            r = x % 10;
            x = x / 10;
            // Check for overflow before doing: num = num * 10 + r
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && r > 7))
                return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && r < -8))
                return 0;

            num = num * 10 + r;
        }
        return num;
    }
};