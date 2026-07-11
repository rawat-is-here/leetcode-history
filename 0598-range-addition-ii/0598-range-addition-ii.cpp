class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // If there are no operations, the entire m x n matrix stays 0,
        // so all m * n elements are technically the "maximum" value.
        for (const auto& op : ops) {
            m = min(m, op[0]); // Find the minimum row restriction
            n = min(n, op[1]); // Find the minimum column restriction
        }
        
        // The total number of maximum elements is the area of the overlapping region
        return m * n;
    }
};