class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        } // hash ready till here
        int max = hash[nums[0]];
        // 1. First find the true maximum degree
        int max_freq = 0;
        for (pair<int, int> num : hash) {
            if (num.second > max_freq) {
                max_freq = num.second;
            }
        }

        // 2. Check the distance for ALL candidates that match max_freq
        int min_len = nums.size();
        for (pair<int, int> num : hash) {
            if (num.second == max_freq) {
                int first = find(nums.begin(), nums.end(), num.first) - nums.begin();
                int last = nums.size() - 1 - (find(nums.rbegin(), nums.rend(), num.first) - nums.rbegin());

                min_len = min(min_len, last - first + 1);
            }
        }
        return min_len;
    }
};