class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Go through each character of the first string
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            
            // Check this character against the same position in all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If the current string is shorter than 'i', or the character doesn't match
                if (i == strs[j].size() || strs[j][i] != c) {
                    // Return everything we've matched up to this point
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};