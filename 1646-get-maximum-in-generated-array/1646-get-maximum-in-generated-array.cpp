class Solution {
public:
    int getMaximumGenerated(int n) {
         if(n==0) return 0;
        if(n==1) return 1;
        vector<int> nums(n+1);
        nums[0] = 0;
        nums[1] = 1;
       
        int upper;
        int max = nums[0];
        upper = (n)/2;
        for(int i = 1;i<=upper;i++)
        {
            if(2*i>=2 && 2*i <=n)
            nums[2*i] = nums[i];
            if(2*i+1>=2 && 2*i+1 <=n)
            nums[2*i+1] = nums[i]+nums[i+1];
        } //array constructed

        for(int i = 0;i<nums.size();i++)
        {
            if(max<nums[i])
            max = nums[i];
        }
        return max;
        
    }
};