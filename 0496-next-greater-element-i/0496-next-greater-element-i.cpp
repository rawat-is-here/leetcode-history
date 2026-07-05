class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int nums2ptr = 0;
        int nums1ptr = 0;
        int count = 0 ;
        map<int, int> equals;
        vector<int> nums1backup(nums1);
        vector<int> nums2backup(nums2);
        for(int i = 0;i<nums1.size();i++)
        {
            for(int j = 0;j<nums2.size();j++)
            {
                if(nums1[i] == nums2[j])
                {
                    equals[i] = nums1[i];
                    break;
                }

            }
        } //equals map is ready with index, value
      
       for(auto it:equals)
       {
        int target_index = find(nums2.begin(), nums2.end(), it.second) - nums2.begin();
        for(int i = target_index + 1; i < nums2.size(); i++){
            if(nums2[i]>it.second)
            {
            result.push_back(nums2[i]);
            count++;
            break;
            }

        }
        if(count == 0)
        result.push_back(-1);
        count=0;


       }
        return result;

        
    }
};