class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            if(max<nums[i])
            max = nums[i];
            if(min>nums[i])
            min = nums[i];
        }
        return gcd(max, min);
        
    }
};