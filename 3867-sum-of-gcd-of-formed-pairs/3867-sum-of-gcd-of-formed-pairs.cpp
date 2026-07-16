class Solution {
public:

    long long gcdSum(vector<int>& nums) {
        
        
        vector<long long> prefixGcd;
        int mxi = 0,gcdfinal;
        long long sum = 0;
        for(int j = 0;j<nums.size();j++)
        {
            sum+=nums[j];
            mxi = max(nums[j], mxi);
            gcdfinal = gcd(nums[j], mxi);
            prefixGcd.push_back(gcdfinal);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        sum = 0;
        for(int a = 0, b = prefixGcd.size()-1; a<b; a++,b--)
        {
            sum = sum+gcd(prefixGcd[a],prefixGcd[b]);
        }
        return sum;
    }
};