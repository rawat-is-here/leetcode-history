class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = 0;
        int n = nums.size();
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]!=nums[k])
            {
                k++;
                nums[k]=nums[i];
            }

        }    
        if(k+1==n)
        return false;
        else return true;    
    }
};