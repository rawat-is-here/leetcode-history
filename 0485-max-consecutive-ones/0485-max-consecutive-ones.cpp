class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ptr= -1; //ptr stays one step behind always
        int count = 0;
        vector<int> result;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 1 && ( ptr<0 || nums[ptr] == 1)) //ya to nums[i] pehla element hai ya lagataar  1 hai
            {
            count++;
            }
            else if(nums[i] == 1 && (ptr >= 0 && nums[ptr] == 0))
            count++; //agar nums[i] pehla element nahi hone ke sath sath uske pehele 0 aa raha hai
            
            else if(nums[i] == 0)
            {
                result.push_back(count);
                count = 0;
            }


            ptr++; //ptr to badhega hi

        }
        //right after the for loop finishes, if with continuous 1 and we ended the array so the count wount have been updated
        if(nums[nums.size()-1] == 1)
        result.push_back(count);
        return *max_element(result.begin(), result.end());

        
    }
};