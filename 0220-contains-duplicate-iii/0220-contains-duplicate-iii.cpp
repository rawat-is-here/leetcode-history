class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window;
        for(int i = 0;i<nums.size();i++)
        {
            //maintain the window
            if(i>indexDiff)
            {
                window.erase(nums[i-(indexDiff+1)]); //erase by value, question si can we write window.begin()+i-(indexDiff+1)
            }
            auto it = window.lower_bound(nums[i]-valueDiff);
            //make the iterator satisfy first condition, 
            //and check if it also satisfies second one
            if(it!=window.end() && *it<=(nums[i]+valueDiff))
            
            return true;

            window.insert(nums[i]); //agar yaha tak aaya hain then element failed, to ab add to karna padega na usko iske andar chahein jo bhi outcome hota
        }
        return false;
        
    }
};
