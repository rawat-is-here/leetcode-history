class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> digitSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);

        vector<long long> compressedValue;
        compressedValue.push_back(0);

        vector<long long> power10(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            int digit = s[i] - '0';

            digitSum[i + 1] = digitSum[i] + digit;
            nonZeroCount[i + 1] = nonZeroCount[i];

            if (digit != 0)
            {
                nonZeroCount[i + 1]++;

                long long newValue = (compressedValue.back() * 10 + digit) % MOD;
                compressedValue.push_back(newValue);
            }
        }

        vector<int> result;

        for (auto &query : queries)
        {
            int l = query[0];
            int r = query[1];

            long long sum = digitSum[r + 1] - digitSum[l];

            int leftCount = nonZeroCount[l];
            int rightCount = nonZeroCount[r + 1];

            int len = rightCount - leftCount;

            long long num = 0;

            if (len > 0)
            {
                num = compressedValue[rightCount] -
                      (compressedValue[leftCount] * power10[len]) % MOD;

                num = (num + MOD) % MOD;
            }

            long long ans = (sum % MOD) * num % MOD;
            result.push_back(ans);
        }

        return result;
    }
};