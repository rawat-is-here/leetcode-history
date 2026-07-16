class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        
        // 1. Find the sum of the very first window of size k
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        
        // 2. Slide the window across the rest of the array
        for (int i = k; i < nums.size(); i++) {
            current_sum += nums[i] - nums[i - k]; // Add new element, remove old element
            max_sum = max(max_sum, current_sum);
        }
        
        // 3. Return the maximum average
        return max_sum / k;
    }
};