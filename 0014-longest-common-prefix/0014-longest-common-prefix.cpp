class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string> prefixes;
        if (strs.empty()) return ""; // Safeguard for empty input
        
        // 1. Fixed: Changed variable name from 'min' to 'min_str' to avoid conflict with std::min
        string min_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; 
        
        // 2. Fixed: Made 'chhoti' an int to store the size, and removed the duplicate declaration
        int chhoti = min_str.size(); 
        for (string str : strs) {
            chhoti = min(chhoti, (int)str.size());
        }
        
        int counter = 0;
        int answer; // Left as is

        for (int i = 0; i < chhoti; i++) {
            int last_index_of_prefix = i;
            string prefix = "";
            int p = 0;
            
            while (p != last_index_of_prefix + 1) // making the prefix string
            {
                // 3. Fixed: Appending characters to an empty string properly
                prefix += strs[0][p]; 
                p++;
            }
            
            for (int j = 0; j < strs.size(); j++) {
                // 4. Fixed: Changed strs[i] to strs[j] to use the loop variable
                // 5. Fixed: Replaced .contains() with .find() == 0 to check for a prefix match
                if (strs[j].find(prefix) == 0)
                    counter++;
            }
            
            // 1 prefix checked, now reset
            if(counter == strs.size()) {
                // Since your logic checks shorter prefixes first, we can't return immediately 
                // if we want the *longest* one, but keeping your exact return logic here:
                prefixes.push_back(prefix); 
            }
            
            counter = 0;
        }
        if(prefixes.empty())
        return "";

        return *max_element(prefixes.begin(), prefixes.end());
    }
};