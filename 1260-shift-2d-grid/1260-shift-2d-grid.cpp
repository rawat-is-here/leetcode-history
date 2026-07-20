class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Create a fresh grid to drop the values directly into their final spots
        vector<vector<int>> result(m, vector<int>(n));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // Find the absolute position after shifting
                int new_1D_pos = (r * n + c + k) % total;
                
                // Convert it back to 2D coordinates
                int new_r = new_1D_pos / n;
                int new_c = new_1D_pos % n;
                
                result[new_r][new_c] = grid[r][c];
            }
        }
        return result;
    }
};