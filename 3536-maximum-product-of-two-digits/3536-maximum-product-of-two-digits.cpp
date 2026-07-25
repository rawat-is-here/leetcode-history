class Solution {
public:
    int maxProduct(int n) {
        int r;
        int max = 0;
        int smax = 0;
        while(n!=0)
        {
            r = n%10;
            n = n/10;
            if(r>max)
            {
                smax = max;
                max = r;
            }
            else if(r<=max && r>smax)
            {
                smax = r;
            }
           

        
        }
        return max*smax;
        
    }
};