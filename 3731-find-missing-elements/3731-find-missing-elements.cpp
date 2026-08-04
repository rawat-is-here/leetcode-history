/*this is just for stream*/

class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        std::vector<int> missing;
        
        // Check every integer between min_val and max_val
        for (int x = min_val + 1; x < max_val; ++x) {
            bool found = false;
            // Brute-force linear scan through nums
            for (int num : nums) {
                if (num == x) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                missing.push_back(x);
            }
        }
        
        return missing;
    }
};