class Solution {

public:

    vector<string> findRelativeRanks(vector<int>& score) {

        vector<string> result(score.size());

        map<int, pair<int,int>> mp;

        for(int i = 0;i<score.size();i++)

        {

             mp[score[i]] = {i,0}; //0 storing in the ranks for now

        } //till here mp will have score, index with score in sorted order

        int n = mp.size();

        int i = 0;

        for(auto &it:mp)

        {

            //if scores are stored sorted, we dont need scores anymore, we will populate ranks alongside the indexes

            (it.second).second = n-i; //think, think.....the scores are sorted

            i++;

        } //we now have indexes, ranks in the value pair of mp

        for(auto it:mp)

        {

            if((it.second).second == 1)

            result[it.second.first] = "Gold Medal";

            else if((it.second).second == 2)

            result[it.second.first] = "Silver Medal";

            else if((it.second).second == 3)

           result[it.second.first] = "Bronze Medal";

            else

            result[it.second.first] = to_string(it.second.second);



        }

        return result;

       

    }

};