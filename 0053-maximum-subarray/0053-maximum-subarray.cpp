class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int maxsum = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            current_sum = max(nums[i], nums[i]+current_sum); //jo mujhe add karke milega, wo better hai, ya fir mai fresh start karu
            maxsum = max(current_sum, maxsum);
        }
        return maxsum;
    }
};
// This choice means:

// If the past streak is positive, extend the length.

// If the past streak is negative, reset the length to 1 and start fresh.
/*
Start at 4. current_sum = 4.

Next element is -1.

Kadane asks: Is it better to start fresh at -1, or keep the streak alive at 3?

3 is better than -1, so Kadane swallows the bad news and keeps moving with current_sum = 3.

Next element is 5.

We add it to our running streak: 3 + 5 = 8. current_sum = 8.

The loop ends. The highest recorded sum is 8 (from the subarray [4, -1, 5]).
*/