class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";
        vector<string> result;
        for(int i = 0;i<words.size();i++)
        {
            string word = words[i];            
            string lower_word = word;
            for(char &ch : lower_word) {
                ch = tolower(ch);
            }
            bool flag = true;
          
            

                if(find(a.begin(), a.end(), lower_word[0])!=a.end())
                {
                    for(int k = 0;k<lower_word.size();k++)
                    {
                        if(find(a.begin(), a.end(), lower_word[k])==a.end())
                        {
                        flag = false;
                       
                        }
                    }
                }
                    if(find(b.begin(), b.end(), lower_word[0])!=b.end())
                {
                    for(int k = 0;k<lower_word.size();k++)
                    {
                        if(find(b.begin(), b.end(), lower_word[k])==b.end())
                        {
                        flag  = false;
                        
                        }
                    }
                }
                    if(find(c.begin(), c.end(), lower_word[0])!=c.end())
                {
                    for(int k = 0;k<lower_word.size();k++)
                    {
                        if(find(c.begin(), c.end(), lower_word[k])==c.end()){
                        flag  = false;
                        
                    }
                    }

                }
            
            if(flag == true)
            result.push_back(word);
            
        }
        return result;
        
    }
};