class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        int digit;
        vector<int> temp;
        while(num!=0)
        {
            digit = num%10;
            temp.insert(temp.begin(),digit);
            num = num/10;
        }
        //number - >array ho gaya
        int k = 0;
        int sum = 0;
        for(int i = 0;i<temp.size();i++)
        {

            if(temp[i]!=0)
            {
            temp[k] = temp[i];
            k++;
           
            }
        } //temp only has my desired value upto k-1 index so i will take my values till there only
        for(int i = 0;i<k;i++)
        {
             sum = sum+temp[i];
            num = num*10+temp[i];
        } //we got the number back
        return (long long)sum*num;
    }
};