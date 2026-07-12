class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<int> temp;
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> dup(img);
        int sum = 0;
        int j;
        for(int i = 0;i<m;i++)
        {
            for( j = 0;j<n;j++)
            {
                vector<int> temp;
                //col-1row-1 + row-1col + col+1row-1
                //col-1row + colrow + col+1row
                //col-1row+1 + colrow+1 + col+1row+1 
                int a = j - 1; // col - 1
                int b = j;     // col
                int c = j + 1; // col + 1
                
                int x = i - 1; // row - 1
                int y = i;     // row
                int z = i + 1; // row + 1
                
                // --- Row x (i - 1) ---
                if(x >= 0 && x < m && a >= 0 && a < n) temp.push_back(img[x][a]);
                if(x >= 0 && x < m && b >= 0 && b < n) temp.push_back(img[x][b]);
                if(x >= 0 && x < m && c >= 0 && c < n) temp.push_back(img[x][c]);
                
                // --- Row y (i) ---
                if(y >= 0 && y < m && a >= 0 && a < n) temp.push_back(img[y][a]);
                if(y >= 0 && y < m && b >= 0 && b < n) temp.push_back(img[y][b]);
                if(y >= 0 && y < m && c >= 0 && c < n) temp.push_back(img[y][c]);
                
                // --- Row z (i + 1) ---
                if(z >= 0 && z < m && a >= 0 && a < n) temp.push_back(img[z][a]);
                if(z >= 0 && z < m && b >= 0 && b < n) temp.push_back(img[z][b]);
                if(z >= 0 && z < m && c >= 0 && c < n) temp.push_back(img[z][c]);

                // This calculation MUST happen inside the inner 'j' loop
                dup[i][j] = accumulate(temp.begin(), temp.end(), 0) / temp.size();
            }

        }
                    return dup;

    }
        
    
};