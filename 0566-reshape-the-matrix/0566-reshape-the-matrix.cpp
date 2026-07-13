class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> wanted(r,vector<int>(c,0));
        int rold = mat.size();
        int cold = mat[0].size();
        if(rold*cold != r*c || rold == r && cold ==c)
        return mat;

        for(int i = 0;i<rold*cold;i++)
        {
            wanted[i/c][i%c] = mat[i/cold][i%cold];
        }
        return wanted;
    }
};