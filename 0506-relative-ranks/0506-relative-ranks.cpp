class Solution {

public:

    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> scoreIndex(score.size());
        vector<string> result(score.size());
       
        for(int i = 0;i<score.size();i++)
        {
            scoreIndex[i] = {score[i],i};
        }
         int n = scoreIndex.size();
        sort(scoreIndex.begin(), scoreIndex.end());
        for(int i = n-1;i>=0;i--)
        {
           if(i==n-1)
           result[scoreIndex[i].second] = "Gold Medal"; 
           else if(i==n-2)
           result[scoreIndex[i].second] = "Silver Medal"; 
           else if(i==n-3)
           result[scoreIndex[i].second] = "Bronze Medal";
           else
           {
            result[scoreIndex[i].second] = to_string(n-i); 
           } 

        }
        return result;


    }

};