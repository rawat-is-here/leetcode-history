class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 0;
        int left = 0;
        
        // 'right' acts as the fast pointer moving forward continuously
        for (int right = 0; right < nums.size(); right++) {
            
            // If the window becomes invalid (diff > 1), shrink it from the left
            while (nums[right] - nums[left] > 1) {
                left++; //SORTED ORDER MEIN, ya to equal aa sakta hai ya fir diff >=1 ok na, to jab jab diff 1 se bada mil raha hai, shrink the windw
            }
            
            // Only measure if it's a strictly harmonious subsequence (diff == 1)
            if (nums[right] - nums[left] == 1) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len;
    }
};