class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;

        k %= totalElements;

        vector<vector<int>> answer(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currentIndex = i * n + j;
                int newIndex = (currentIndex + k) % totalElements;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                answer[newRow][newCol] = grid[i][j];
            }
        }

        return answer;
    }
};