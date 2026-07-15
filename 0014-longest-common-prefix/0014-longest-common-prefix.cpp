class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string> prefixes;
        if (strs.empty()) return ""; // Safeguard for empty input
        int counter = 0;
        string prefix;
        string min_str = strs[0]; 
        for(string str: strs)
        {
            if(min_str.size() > str.size())
            min_str = str;
        }

        for(int i = 0;i<min_str.size();i++)
        {
            prefix = prefix + min_str[i];
            for(string str : strs)
            {
                if(str.find(prefix) == 0)
                counter++;
            }
             if(counter == strs.size())
        prefixes.push_back(prefix);
            counter = 0;
        }
        if(prefixes.empty())
        return "";
        return prefixes[prefixes.size()-1];
       
    }
};