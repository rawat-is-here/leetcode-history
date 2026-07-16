#include <vector>
#include <algorithm>
#include <numeric> // Essential for optimized std::gcd

using namespace std;

// Fast I/O optimization trick for Leetcode competitive environments
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        
        // Optimize 1: Allocate exact memory upfront to avoid overhead allocations
        vector<int> prefixGcd(n); 
        
        int mxi = 0;
        for(int j = 0; j < n; j++) {
            if (nums[j] > mxi) {
                mxi = nums[j];
            }
            // Optimize 2: Use compiler-optimized built-in GCD
            prefixGcd[j] = std::gcd(nums[j], mxi); 
        }
        
        // Sorting remains O(n log n)
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long sum = 0;
        int half = n / 2;
        
        // Optimize 3: Simplified loop bounds for cleaner CPU assembly compilation
        for(int a = 0; a < half; a++) {
            sum += std::gcd(prefixGcd[a], prefixGcd[n - 1 - a]);
        }
        
        return sum;
    }
};