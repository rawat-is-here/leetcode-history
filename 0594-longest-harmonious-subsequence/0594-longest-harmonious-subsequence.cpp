class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        vector<int> temp(1, 0);
        sort(nums.begin(), nums.end());
        int k = 0;
        int i = nums.size() - 1;
        while (k < i)
        {

            if (nums[i] - nums[k] == 1)
            {

                temp.push_back(i - k + 1); // stores all possible combs of the hamonious subsequence
                // for the first time, i will be at the last occurence of max, and k will be at first of min
                k++;
                i = nums.size() - 1;
            }
            else
            {
                i--;
                // SAFETY PATCH: If i has decremented down to k,
                // it means no "+1" match exists for this specific k.
                if (i <= k)
                {
                    k++;                 // Move to the next min candidate
                    i = nums.size() - 1; // Reset i back to the end
                }
            }
        }
        return *max_element(temp.begin(), temp.end());
    }
};