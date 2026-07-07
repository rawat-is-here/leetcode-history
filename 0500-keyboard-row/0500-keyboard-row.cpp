class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1  = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        vector<string> result;
        for(string word:words)
        {
            int row[3] = {0,0,0};

            for(char ch:word)
            {
                ch = tolower(ch);
                if(find(row1.begin(), row1.end(), ch)!=row1.end())
                row[0] = 1;
                else if(find(row2.begin(), row2.end(), ch)!=row2.end())
                row[1] = 1;
                else if(find(row3.begin(), row3.end(), ch)!=row3.end())
                row[2] = 1;
            }
            if(row[0]+row[1]+row[2]==1)
            result.push_back(word);

        }
              return result;
        
    }
};