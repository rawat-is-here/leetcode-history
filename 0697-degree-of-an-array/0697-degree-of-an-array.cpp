class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // Map stores: element -> {frequency, first_seen_index, last_seen_index}
        unordered_map<int, vector<int>> hash; 
        int max_freq = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                // First time seeing the element: set freq=1, first=i, last=i
                hash[nums[i]] = {1, i, i};
            } else {
                // Already seen: increment freq, update last seen to current index i
                hash[nums[i]][0]++;
                hash[nums[i]][2] = i;
            }
            max_freq = max(max_freq, hash[nums[i]][0]);
        }
        
        int min_len = nums.size();
        
        // Find the minimum length among all elements that match max_freq
        for (auto& pair : hash) {
            int freq = pair.second[0];
            int first = pair.second[1];
            int last = pair.second[2];
            
            if (freq == max_freq) {
                min_len = min(min_len, last - first + 1);
            }
        }
        
        return min_len;
    }
};