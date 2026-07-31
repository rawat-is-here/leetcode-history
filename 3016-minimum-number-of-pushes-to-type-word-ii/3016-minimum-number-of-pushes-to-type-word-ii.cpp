class Solution {
public:
    int minimumPushes(std::string word) {
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        std::sort(freq.rbegin(), freq.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26 && freq[i] > 0; ++i) {
            int pushesPerChar = (i / 8) + 1;
            totalPushes += freq[i] * pushesPerChar;
        }
        
        return totalPushes;
    }
};
// /*this is only for streak, i know nothing*/