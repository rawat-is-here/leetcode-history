class Solution {
public:
    string to_binary(int n)
    {
       
        vector<int> bin;
        string str = "";
        int r = 0;
        if(n==0)
        bin.push_back(0);
        
        while(n!=0)
        {
            r = n%2;
            n = n/2;
            bin.insert(bin.begin(),r);
        }

        for(int num:bin)
        str = str+(char)('0'+num);
        return str;
    }

    int from_binary(string a)
    {
        int num = 0;
        for(int i = a.size()-1;i>=0;i--)
        {
            num = num + pow(2,i)*(a[a.size()-1-i]-'0');
        }
        return num;
    }
    string addBinary(string a, string b) {
        return to_binary(from_binary(a)+from_binary(b));
    }
};
//this will overflow in case of lloooong strings
