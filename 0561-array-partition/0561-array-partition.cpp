class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        n = n/2;
        //agar maine sort kiya uske baad, i need ki maximum should be the sums of minimum hone ke liye, jisko minimum liya ho usse JUST bada uska pair ho
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum = sum+nums[2*i];
        }
        return sum;
    }
};