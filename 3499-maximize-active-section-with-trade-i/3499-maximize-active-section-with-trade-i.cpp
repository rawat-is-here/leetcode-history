class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;

        for (char ch : s) {
            if (ch == '1') {
                originalOnes++;
            }
        }

        vector<string> chunks;
        string temp(1, s[0]);

        // Build chunks of consecutive equal characters.
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == temp.back()) {
                temp += s[i];
            } else {
                chunks.push_back(temp);
                temp = string(1, s[i]);
            }
        }

        // Push the final chunk.
        chunks.push_back(temp);


        int bestGain = 0;

        // Search only for valid 0-block | 1-block | 0-block patterns.
        for (int i = 0; i + 2 < chunks.size(); i++) {
            if (chunks[i][0] == '0' &&
                chunks[i + 1][0] == '1' &&
                chunks[i + 2][0] == '0') {

                int currentGain =
                    chunks[i].size() + chunks[i + 2].size();

                bestGain = max(bestGain, currentGain);
            }
        }

        return originalOnes + bestGain;
    }
};