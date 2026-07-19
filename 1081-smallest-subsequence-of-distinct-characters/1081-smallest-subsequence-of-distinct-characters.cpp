class Solution {
public:
    string smallestSubsequence(string s) {
        // Step 1: Find the last occurrence index of each character
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        
        // Step 2: Use a string as a stack, and a boolean array to track what's in it
        string result = ""; // This acts as our monotonic stack
        vector<bool> seen(26, false);
        
        // Step 3: Iterate through the string and build the result greedily
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            
            // If the character is already in our stack, skip it
            if (seen[curr - 'a']) continue;
            
            // While the stack is not empty, AND the top of the stack is lexicographically
            // larger than curr, AND that top character appears again later in the string...
            while (!result.empty() && result.back() > curr && lastIdx[result.back() - 'a'] > i) {
                // Pop it from the stack and mark it as unseen so we can use it later
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Push the current character into the stack and mark it seen
            result.push_back(curr);
            seen[curr - 'a'] = true;
        }
        
        return result;
    }
    };