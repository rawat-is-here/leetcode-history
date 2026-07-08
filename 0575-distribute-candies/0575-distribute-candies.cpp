class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        // lets do it first as removing duplicate
        int k = 0;
        for (int i = 1; i < candyType.size(); i++) {
            if (candyType[i] !=candyType[k]) // if found something unique then only
            {
                k++;
                candyType[k] = candyType[i];
            }
        }
        // till here we will have unqiue toffees till index k, i.e size k+1
        if(k+1 >= candyType.size()/2)
        return candyType.size()/2;
        else 
        return k+1;

    }
};