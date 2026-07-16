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