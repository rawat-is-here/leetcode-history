class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // i get a feel of circular arrangement and hence i feel that %m and %n
        // will be heavily involved
        int m = grid.size();
        int n = grid[0].size();
        for (int w = 1; w <= k; w++) {
            vector<int> last(m);
            for (int i = 0; i < m; i++)
                last[i] = grid[i][n - 1];

            for (int col = n - 2; col >= 0; col--) {
                for (int elements_of_that_col = 0; elements_of_that_col < m; elements_of_that_col++) {
                    grid[elements_of_that_col][col+1] = grid[elements_of_that_col][col];
                }
                // when it reaches here first column needs to be filled with
                // last
            } // half step done now we need to circularise the first column
            for (int i = 0; i < m; i++)
                grid[i][0] = last[i];
            // now remains final one more circular turn
            int last_element = grid[m - 1][0];
            for (int j = m - 2; j >= 0; j--) {
                grid[j+1][0] = grid[j][0];
            }
            grid[0][0] = last_element;
        }
        return grid;
    }
};