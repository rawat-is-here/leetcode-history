class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        int MOD = 1e9 + 7;
        
        // dp[x][y] stores the number of disjoint pairs of subsequences
        // where gcd(seq1) = x and gcd(seq2) = y.
        // 0 represents an empty subsequence.
        vector<vector<int>> dp(max_num + 1, vector<int>(max_num + 1, 0));
        dp[0][0] = 1; // Base case: both sequences start empty
        
        for (int num : nums) {
            // Option 1: Skip the current 'num' entirely (inherits the current dp states)
            vector<vector<int>> next_dp = dp; 
            
            for (int x = 0; x <= max_num; ++x) {
                for (int y = 0; y <= max_num; ++y) {
                    if (dp[x][y] == 0) continue;
                    
                    // Option 2: Add 'num' to the first subsequence (seq1)
                    int new_x = std::gcd(x, num);
                    next_dp[new_x][y] = (next_dp[new_x][y] + dp[x][y]) % MOD;
                    
                    // Option 3: Add 'num' to the second subsequence (seq2)
                    int new_y = std::gcd(y, num);
                    next_dp[x][new_y] = (next_dp[x][new_y] + dp[x][y]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        long long total_pairs = 0;
        // Sum up all states where both sequences are non-empty (g > 0) and have the same GCD
        for (int g = 1; g <= max_num; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};