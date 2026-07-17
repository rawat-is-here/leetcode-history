class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries){

        int max_val = *max_element(nums.begin(), nums.end());
    vector<int> count(max_val + 1, 0);
    for (int i:nums) {
        count[i]++;
    }
    // frequency calculation done
    vector<long long> gcdcount(max_val + 1);
    for (int factor = max_val; factor >= 1;factor--) // i wonder what if i make the loop from 1 to max
    {
        // vector<int> gcdcount(max_val+1);
        for (int i = factor; i <= max_val; i += factor) {
            gcdcount[factor] = gcdcount[factor] + count[i];
        }
        gcdcount[factor] = gcdcount[factor] * (gcdcount[factor] - 1) / 2;
        for (int multiple = 2 * factor; multiple <= max_val; multiple += factor) {
    gcdcount[factor] -= gcdcount[multiple];
}
        // here total number of multiples are converted to their pairs

    } // when the compiler reaches here we will have gcdcount[] ready which will
      // store number of pairs in the array for each factor 'g'
    // now we need cumulative frequency implementation here

    vector<long long> cumulative(max_val + 1, 0);
    for (int i = 1; i <= max_val; i++) {
        cumulative[i] = cumulative[i - 1] + gcdcount[i]; // this implementation gives us
                                             // what we needs without sorting
    }
    vector<int> answer;
    for (long long q : queries) {
        auto it = upper_bound(cumulative.begin(), cumulative.end(), q);
        // finds the just greater one
        int actual_gcd = distance(cumulative.begin(), it); // finds the distace
        answer.push_back(actual_gcd);
    }

    return answer;

}
}
;