class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(vector<int> op:ops)
        {
            for(int i = 0;i<op[0];i++)
            {
                for(int j = 0;j<op[1];j++)
                {
                    matrix[i][j]++;

                }
            }
        }
        int max = matrix[0][0];
        for(vector<int> row : matrix)
        {
            for(int element : row)
            {
            if (element > max)
            {
            max = element;
            count = 1;
            }
            else if(element == max)
            count++;
            }
        }
        return count;
        
    }
};
