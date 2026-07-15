class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_freq = 0;
        int length = INT_MAX;
        unordered_map<int, vector<int>> hash; //stores freq, first, last
        for(int i = 0;i<nums.size();i++)
        {
            if(hash.find(nums[i]) == hash.end()) //if it doesnt exist
            hash[nums[i]] = {1,i,i};
            else 
            //if it exists
            {
                hash[nums[i]][0]++;
                hash[nums[i]][2] = i;
            }
             max_freq = max(max_freq, hash[nums[i]][0]);
        } //till here every element will be done in the map, and now whats left is
        for (auto it:hash)
        {
            if(it.second[0] == max_freq)
            length = min(length,(it.second[2] - it.second[1]+1));
            
        }
        return length;
            
    }
        };