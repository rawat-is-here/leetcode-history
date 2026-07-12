class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> temp(operations.size());
        int asciiC = 67;
        int asciiD = 68;
        int asciiplus = 43;
        for(int i = 0;i<operations.size();i++)
        {
            if(!(operations[i] == "D" || operations[i] == "C" || operations[i] == "+")) //agar inek alawa kuch bhi hai to
            temp.push_back(stoi(operations[i]));
            else if(operations[i] == "C")
            temp.pop_back();
            else if(operations[i] == "D")
            temp.push_back(temp[temp.size()-1]*2);
            else if(operations[i] == "+")
            temp.push_back(temp[temp.size()-1]+temp[temp.size()-2]);
        }
        return accumulate(temp.begin(), temp.end(), 0);



        
        


        
    }
};