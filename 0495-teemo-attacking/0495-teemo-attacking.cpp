class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for(int i = 0;i<timeSeries.size()-1;i++)
        {
            if(timeSeries[i+1]-timeSeries[i] <= duration)
            {
                total = total + timeSeries[i+1] - timeSeries[i];
            }
            else
            {
                total = total + duration;
            }

        
        }
        //the last attack got left
        total = total+duration;
        return total;

        
    }
};