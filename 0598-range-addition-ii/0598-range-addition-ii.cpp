class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> matrix(m, vector<int> (n,0));
        for(int i = 0;i<ops.size();i++)
        {
            int row = ops[i][0];
            int column = ops[i][1];
            if(row<=m && column<=n)
            {
                for(int j = 0;j<row;j++)
                {
                    for(int k = 0;k<column;k++)
                    {
                        matrix[j][k]++;
                    }
                }
            }
        }
        int max = matrix[0][0];
        int count = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]>max)
                {
                max = matrix[i][j];
                }
            }
        }
        int max_val = matrix[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == max_val) {
                    count++;
                }
            }
        }

        return count;
    }
};
    
