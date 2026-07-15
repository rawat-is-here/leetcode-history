class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // perimeter me 1 kab judega? jab 1 side koi na ho, matlab 3 sides
        // occupied perimeter me 2 kab judega? jab 2 sides koi na ho 3 kab
        // judega ? jab 3 sides koi na ho, matlab 1 occupied ho 4 kab judega?
        // jab chaaro side koii na ho, matlab desserted alone 0 kab judega, jab
        // 0 sides koi naho, matlab completely occupied by all 4
        //  so lets do this
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // We only calculate perimeter if the current cell is land (1)
                if (grid[i][j] == 1) {
                    int free = 0;

                    // 1. Up Check: Boundary OR Water
                    if (i == 0 || grid[i - 1][j] == 0)
                        free++;

                    // 2. Down Check: Boundary OR Water
                    if (i == m - 1 || grid[i + 1][j] == 0)
                        free++;

                    // 3. Left Check: Boundary OR Water
                    if (j == 0 || grid[i][j - 1] == 0)
                        free++;

                    // 4. Right Check: Boundary OR Water
                    if (j == n - 1 || grid[i][j + 1] == 0)
                        free++;

                    perimeter += free;
                }
            }
        }
        return perimeter;
    }
};