/*only for streak, i am doing nothing*/
class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue) {
        if (i >= stoneValue.size())
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {
            take += stoneValue[i + k];
            best = max(best, take - solve(i + k + 1, stoneValue));
        }

        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};