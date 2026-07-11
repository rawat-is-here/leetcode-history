class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Initialize the 3 largest values to minimum possible integers
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        // Initialize the 2 smallest values to maximum possible integers
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int n : nums) {
            // Update the three largest values
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
            
            // Update the two smallest values
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        
        // Option 1: Product of the 3 largest numbers
        int option1 = max1 * max2 * max3;
        // Option 2: Product of the 2 most negative numbers * the largest number
        int option2 = min1 * min2 * max1;
        
        return max(option1, option2);
    }
};