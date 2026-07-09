/*This solution is only being submitted to maintain the streak, I dont know code about graph*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Precompute component IDs for each node
        vector<int> comp(n, 0);
        int current_id = 0;
        
        for (int i = 1; i < n; i++) {
            // If the gap between adjacent elements is too large, it splits the component
            if (nums[i] - nums[i-1] > maxDiff) {
                current_id++;
            }
            comp[i] = current_id;
        }
        
        // Step 2: Answer each query in O(1) time
        vector<bool> ans;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            // If they belong to the exact same component, a path exists
            ans.push_back(comp[u] == comp[v]);
        }
        
        return ans;
    }
};