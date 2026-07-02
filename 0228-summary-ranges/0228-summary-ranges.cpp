class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ranges;
        int counter = 0;
        vector<int> temp;

        if (nums.empty()) return ranges;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (counter == 0)
                temp.push_back(nums[i]);

            if ((long long)nums[i + 1] - nums[i] == 1)
            {
                temp.push_back(nums[i + 1]);
                counter++;
            }

            else if ((long long)nums[i + 1] - nums[i] != 1 && counter == 0)
            {
                ranges.push_back(to_string(temp[0]));
                temp.clear();
                counter = 0;
            }

            else if((long long)nums[i + 1] - nums[i] != 1 && counter!= 0)
            {
                ranges.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));
                temp.clear();
                counter = 0;
            }
        }

        if (!temp.empty())
        {
            if (temp.size() == 1)
                ranges.push_back(to_string(temp[0]));
            else
                ranges.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));
        }
        else
        {
            ranges.push_back(to_string(nums.back()));
        }

        return ranges;
    }
};
