class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0, sumeven = 0;
        for(int i = 1;i<=n;i++)
        {
            sumodd = sumodd + 2*i-1;
            sumeven = sumeven + 2*i;
        }
        while(sumodd > 0 && sumeven>0)
        {
            sumodd = sumodd%sumeven;
            sumeven = sumeven% sumodd;
            if(sumeven==0)
            return sumodd;
            else return sumeven;
        }
        return 0;
        
    }
};