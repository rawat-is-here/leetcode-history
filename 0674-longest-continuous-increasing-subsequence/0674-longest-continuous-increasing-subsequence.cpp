class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty input safely

        int max_len = 1;
        int current_len = 1;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                // Streak continues
                current_len++;
            } else {
                // Streak broke, update max and reset current streak
                max_len = max(max_len, current_len);
                current_len = 1;
            }
        }

        // One final check in case the longest streak extended to the very end
        return max(max_len, current_len);
    }
};