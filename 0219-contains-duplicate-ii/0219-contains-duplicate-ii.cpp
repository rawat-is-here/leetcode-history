class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window(k);
        for(int i = 0;i<nums.size();i++)
        {
            if(i>k) 
            {
            window.erase(nums[i-(k+1)]);
            } //size management
            if(window.count(nums[i]))
            return true;
            else
            window.insert(nums[i]);
            
            
            


        }
        return false;
}
};