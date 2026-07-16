class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        for(int length = 2;length<=9;length++)
        {
            for(int i = 0;i<=9-length;i++)
            {
                int num = stoi(digits.substr(i,length));
            
            if(num>=low && num<=high)
            result.push_back(num);\
            }
        }
        return result;
    }
};