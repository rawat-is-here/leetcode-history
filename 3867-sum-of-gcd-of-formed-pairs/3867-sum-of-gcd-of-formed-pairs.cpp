class Solution {
public:
int gcd(int a, int b)
        {
            
            while(a!=0 && b!=0)
            {
                if(a>b)
                a = a%b;
                else
                b = b%a;
            }
                if(b == 0)
                return a;
                else 
                return b;
      
        }
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