class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> wanted(r, vector<int>(c, 0));
        int rold = mat.size();
        int cold = mat[0].size();
        if(rold*cold != r*c)
        return mat;

        vector<int> hash(rold*cold+1);
        //i am guessing the brute force as first traversing the original using hash, and then storing it in new
        int index = 0;
        for(int i = 0;i<rold;i++)
        {
            for(int j = 0;j<cold;j++)
            {
                hash[index] = mat[i][j];
                index++; 
            }
        }
        //till here we have hash mapped
        index = 0;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                wanted[i][j] = hash[index];
                index++;
            }
        }
        return wanted;
    }
};