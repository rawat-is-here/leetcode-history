class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ptrprev = -1;
        int ptrnext = 1;
        int count = 0;
        
        if(n==0)
        return true;

        if(flowerbed.size()==1)
        {
            if(flowerbed[0] == 1)
            return false;
            else return true;
        }

        for(int i = 0;i<flowerbed.size();i++)
        {
            if(i == 0)
            {
                if(flowerbed[i] == 0 && flowerbed[ptrnext]==0)
                {
                    flowerbed[i] = 1;
                    count++;
                }
                else {} //do nothing
            }
            else if(i == flowerbed.size()-1)
            {
                if(flowerbed[i]==0 && flowerbed[ptrprev] == 0)
                {
                    flowerbed[i] = 1;
                    count++;
                }
                else {} //do nothing
            }
            else
            {
                if(flowerbed[i] == 0 && flowerbed[ptrprev] == 0 && flowerbed[ptrnext] == 0)
                {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            
            ptrnext++;
            ptrprev++;
            
        }
        if(n<=count)
        return true;
        else return false;
    }
};