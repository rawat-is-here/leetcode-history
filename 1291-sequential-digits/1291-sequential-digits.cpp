class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int> temp;
        int num = 0;

        for(int i = 1; i<=9;i++)
        {
            num = 0;
            num = num*10+i;
            for(int j = i+1;j<=9;j++)
            {
               
                    num = num*10+j;
                    if(num<=high && num>=low)
                    temp.push_back(num);

                    else if(num<low)
                    continue;
                    
                    else if(num>high)
                    break;
            }

            // temp.push_back(i); //single digits always sequential
            
        }
        sort(temp.begin(), temp.end());
    return temp;
        
    }
};