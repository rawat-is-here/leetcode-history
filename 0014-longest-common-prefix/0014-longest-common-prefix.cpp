class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        if (strs.empty()) return ""; // Safeguard for empty input
        int counter = 0;
        string prefix;
        string result = "";
        for(int i = 0;i<strs[0].size();i++)
        {
            prefix = prefix + strs[0][i];
            for(string str : strs)
            {
                if(str.find(prefix) == 0)
                counter++;
            }
             if(counter == strs.size())
             result = prefix;
             
             counter = 0;
        }
       
        return result;
       
    }
};