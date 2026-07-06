class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int counter = 0;
        vector<int> temp;
        vector<string> range;
        if (nums.empty())
            return range;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (counter == 0)
                temp.push_back(nums[i]);

            if (nums[i + 1] == nums[i] + 1) {
                temp.push_back(nums[i + 1]);
                counter++;
            } else if (nums[i + 1] != nums[i] + 1 &&
                       counter == 0) // unique item
            {
                range.push_back(to_string(temp[0]));
                temp.clear();
                counter = 0;
            } else if (nums[i + 1] != nums[i] + 1 && counter != 0)
            // this means end of range
            {
                range.push_back(to_string(temp.front()) + "->" +
                                to_string(temp.back()));
                temp.clear();
                counter = 0;
            }
        }
        // now what if the last element is left out? we are doing all this for
        // last left out element
        if (!temp.empty()) {
            if (temp.size() == 1) // there is a last unique element left
                range.push_back(to_string(temp[0]));
            // what if at last there is a range's last element
            else if (temp.size() > 1) {
                range.push_back(to_string(temp.front()) + "->" +
                                to_string(temp.back()));
            }
        }
         else

        {
            range.push_back(to_string(nums.back()));
        }
        return range;
    }
};