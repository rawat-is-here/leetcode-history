class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> temp;
        int count = 0;
        if(nums.size()==1)
        return 1;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] < nums[i+1])
            {
                count++;
            }
            else
            {
                temp.push_back(count+1);
                count = 0;

            }

        }
        if(nums[nums.size()-1] > nums[nums.size()-2] && count !=0) //if it was an onogin streak and last one left out
        {
        count++;
        temp.push_back(count);
        }

        else if(nums[nums.size()-1] < nums[nums.size()-2]) //if last element is lesser than second last like 1 3 5 2, so by then coming till 2 will already have count, just make sure that unique element is recorded
        temp.push_back(1);

        
        
        return *max_element(temp.begin(), temp.end());
    }
};