class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Clone the original array to preserve positions
        vector<int> sorted_arr = arr;
        
        // Step 2: Sort the cloned array
        sort(sorted_arr.begin(), sorted_arr.end());
        
        // Step 3: Build the rank map directly
        unordered_map<int, int> rank_map;
        int rank = 1;
        for (int num : sorted_arr) {
            // Only assign a rank if the number hasn't been seen yet
            if (rank_map.find(num) == rank_map.end()) {
                rank_map[num] = rank;
                rank++;
            }
        }
        
        // Step 4: Transform the original array into ranks
        vector<int> result;
        result.reserve(arr.size()); // Optimization: allocates memory upfront
        for (int num : arr) {
            result.push_back(rank_map[num]);
        }
        
        return result;
    }
};