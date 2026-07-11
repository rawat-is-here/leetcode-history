#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> output;
        int min_sum = INT_MAX;
        
        // Step 1: Map each restaurant in list1 to its original index
        for (int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }
        
        // Step 2: Traverse list2 to find common restaurants
        for (int j = 0; j < list2.size(); j++) {
            // Check if the restaurant from list2 was also in list1
            if (map.find(list2[j]) != map.end()) {
                int current_sum = j + map[list2[j]];
                
                // If we found a NEW strictly smaller index sum
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    output.clear();             // Clear old sub-optimal results
                    output.push_back(list2[j]); // Start fresh with this new minimum
                } 
                // If we found a TIE (equal to the current minimum index sum)
                else if (current_sum == min_sum) {
                    output.push_back(list2[j]); // Add it to our tied results
                }
            }
        }
        
        return output;
    }
};