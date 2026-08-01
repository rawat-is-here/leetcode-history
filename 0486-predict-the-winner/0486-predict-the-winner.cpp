/*only for streak purpose, i know nothing*/
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Fast path: Even-length arrays are always a win for Player 1
        if (n % 2 == 0) return true;
        
        // dp[j] stores the maximum net score differential for subarray nums[i...j]
        vector<int> dp = nums;
        
        // Build the table from smaller subarrays to larger ones
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        
        // Player 1 wins if their net score differential is >= 0
        return dp[n - 1] >= 0;
    }
};