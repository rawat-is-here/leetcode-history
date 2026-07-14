class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> firstIndex;
        unordered_map<int, int> lastIndex;

        int degree = 0;

        // Store frequency, first index and last index
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];

            // Record the first occurrence only once
            if (firstIndex.find(value) == firstIndex.end()) {
                firstIndex[value] = i;
            }

            frequency[value]++;
            lastIndex[value] = i;

            degree = max(degree, frequency[value]);
        }

        int minimumLength = nums.size();

        // Check every number that creates the array's degree
        for (const auto& entry : frequency) {
            int value = entry.first;
            int count = entry.second;

            if (count == degree) {
                int length = lastIndex[value] - firstIndex[value] + 1;
                minimumLength = min(minimumLength, length);
            }
        }

        return minimumLength;
    }
};