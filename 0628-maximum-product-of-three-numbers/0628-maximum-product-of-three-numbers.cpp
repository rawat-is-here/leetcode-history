class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3;
        max1 = INT_MIN;
        max2 = INT_MIN;
        max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i = 0;i<nums.size();i++) //we took max1>max2>max3
    {
        if(nums[i]>=max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if(nums[i]>=max2 && nums[i]<=max1)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if(nums[i] >= max3 && nums[i] <= max2 && nums[i] <= max1)
        {
            max3 = nums[i];
        }
        if(nums[i]<=min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if(nums[i] >= min1 && nums[i] <= min2)
        {
            min2 = nums[i];
        }
    }
   int option1 = max1*max2*max3;
   int option2 = min1*min2*max1;
   return max(option1, option2);
    }
};