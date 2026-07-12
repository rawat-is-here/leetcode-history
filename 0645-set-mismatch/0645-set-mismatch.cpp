class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int lost, duplicate;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                duplicate = nums[i];        
            }
        
        } //now the lost elemenent can be duplicate + diff or duplicate -diff
        int diff = abs((n*(n+1)/2)-accumulate(nums.begin(), nums.end(), 0));
        if(n*(n+1)/2 > accumulate(nums.begin(), nums.end(), 0))
        lost = duplicate+diff;
        else
        lost = duplicate-diff;

        result.push_back(duplicate);
        result.push_back(lost);
        return result;

    }
};