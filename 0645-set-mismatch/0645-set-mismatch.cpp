class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int duplicate = -1;
        int lost = -1;
        
        // Step 1: Find the duplicate using negative marking
        for (int i = 0; i < nums.size(); i++) {
            int val = std::abs(nums[i]);
            if (nums[val - 1] < 0) {
                duplicate = val; // Already marked, so it's the duplicate
            } else {
                nums[val - 1] *= -1; // Mark as visited
            }
        }
        
        // Step 2: Find the missing number (the index that remains positive)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                lost = i + 1;
                break;
            }
        }
        
        return {duplicate, lost};
    }
};