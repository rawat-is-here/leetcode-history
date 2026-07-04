class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ptr= -1; //ptr stays one step behind always
        int count = 0;
        vector<int> result;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 1 && ( ptr<0 || nums[ptr] == 1)) //nums i 1 ho provided that uske pehle wala bhi ek ho ya fir ho hi na, yani ya fir pehla hi element 1 ho, to fir count badhao
            {
            count++;
            }
            else if(nums[i] == 1 && ( (ptr >= 0 && nums[ptr] == 0) || (ptr + 2 < nums.size() && nums[ptr + 2] == 0) ))
            count++; //handles isolated single 1
            
            else if(nums[i] == 0)
            {
                result.push_back(count);
                count = 0;
            }


            ptr++; //ptr to badhega hi

        }
        //right after the for loop finishes, with continuous 1 and we ended the array
        result.push_back(count);
        return *max_element(result.begin(), result.end());

        
    }
};