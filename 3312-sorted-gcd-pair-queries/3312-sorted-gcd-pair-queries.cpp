class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Find the maximum value in the nums array to establish our range
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count how many times each number appears in the input array
        vector<long long> count(max_val + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        
        // gcd_counts[g] will store the exact number of pairs whose GCD is exactly g
        vector<long long> gcd_counts(max_val + 1, 0);
        
        // Step 2: Work backwards from max_val down to 1
        for (int g = max_val; g >= 1; g--) {
            
            // Count how many total numbers in nums are multiples of g
            long long total_multiples = 0;
            for (int multiple = g; multiple <= max_val; multiple += g) {
                total_multiples += count[multiple];
            }
            
            // Calculate total possible pairs that share g as a common divisor
            long long total_pairs = total_multiples * (total_multiples - 1) / 2;
            
            // Subtraction Step: Remove the pairs whose GREATEST common divisor 
            // is actually a strictly higher multiple of g (e.g., 2g, 3g, 4g...)
            for (int multiple = 2 * g; multiple <= max_val; multiple += g) {
                total_pairs -= gcd_counts[multiple];
            }
            
            // Store the finalized exact count of pairs for GCD = g
            gcd_counts[g] = total_pairs;
        }
        
        // Step 3: Create a running total (Prefix Sum) of the GCD counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_counts[i];
        }
        
        // Step 4: Map each query index to its corresponding GCD using binary search
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (long long q : queries) {
            // upper_bound finds the first position where the prefix sum is strictly greater than q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            int actual_gcd = distance(prefix_sums.begin(), it);
            answer.push_back(actual_gcd);
        }
        
        return answer;
    }
};