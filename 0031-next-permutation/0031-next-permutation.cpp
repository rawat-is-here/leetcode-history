class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //ye completely maine socha tha, peeche se ye dekho ki ascend kar raha hai ya nahi karr raha the moment you found a non sroted digit, swap it with the next one, just gemini changed it swap it with the upper bound one, to find just,....just next bigger one
        int swapper;
        for(int i = nums.size()-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1]) //wherever the ascending order is broken
            {
                for(int j = i;j<nums.size();j++)
                {
                    if(nums[j]>nums[i-1])
                    {
                        swapper = j; //the last j to be entered into the swapper is the real element upper bounder
                    }
                }
                swap(nums[i-1],nums[swapper]);
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        //reached here means the whole array is descneding
        sort(nums.begin(), nums.end());
        
    }
};