class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 1. Sort the vector normally (ascending order)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // 2. Scenario A: The 3 largest numbers
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        // 3. Scenario B: The 2 smallest (most negative) numbers * the largest number
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        // 4. Return the maximum of the two options
        return max(option1, option2);
    }
};