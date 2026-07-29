/*this solution is only for streak, nothing mine*/
class Solution {
public:
    const long long LIM = 1000001;

    vector<long long> fact;

    long long mulCap(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        if (a > LIM / b) return LIM;
        return min(LIM, a * b);
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;

        // Compute multinomial carefully using combinations
        int rem = total;
        for (int c : cnt) {
            if (c == 0) continue;

            long long comb = 1;
            for (int i = 1; i <= c; i++) {
                comb = comb * (rem - c + i) / i;
                if (comb > LIM) comb = LIM;
            }

            ans = mulCap(ans, comb);
            rem -= c;
            if (ans >= LIM) return LIM;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
            half[i] = freq[i] / 2;
        }

        if (countWays(half) < k)
            return "";

        string left = "";

        int len = 0;
        for (int x : half) len += x;

        while (len--) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};