/*Only for maintaining streak, does not know anything*/
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Get sorted unique values
        vector<int> unique_vals = nums;
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
        
        int m = unique_vals.size();
        // up[i][j] stores the index you reach from unique_vals[i] after 2^j maximum right-jumps
        int max_powers = 20; 
        vector<vector<int>> up(m, vector<int>(max_powers));

        // Step 2: Precompute the immediate 1-step max jump (2^0) for each unique value
        for (int i = 0; i < m; ++i) {
            long long target = (long long)unique_vals[i] + maxDiff;
            // Find the furthest element we can reach to the right
            auto it = upper_bound(unique_vals.begin(), unique_vals.end(), target);
            int jump_idx = distance(unique_vals.begin(), it) - 1;
            up[i][0] = jump_idx;
        }

        // Step 3: Build the binary lifting table (up[i][j] = up[ up[i][j-1] ][j-1])
        for (int j = 1; j < max_powers; ++j) {
            for (int i = 0; i < m; ++i) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }

        // Step 4: Answer each query in O(log M) time
        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int val_u = nums[u];
            int val_v = nums[v];

            if (val_u == val_v) {
                answer.push_back(1); // Different indices, same value -> 1 jump away
                continue;
            }

            // Ensure we are always jumping from smaller to larger value
            if (val_u > val_v) {
                swap(val_u, val_v);
            }

            int idx_u = lower_bound(unique_vals.begin(), unique_vals.end(), val_u) - unique_vals.begin();
            
            int steps = 0;
            // Use binary lifting to make large jumps toward val_v
            for (int j = max_powers - 1; j >= 0; --j) {
                int next_idx = up[idx_u][j];
                if (unique_vals[next_idx] < val_v) {
                    idx_u = next_idx;
                    steps += (1 << j);
                }
            }

            // Take the final single step to completely reach or cross val_v
            idx_u = up[idx_u][0];
            steps++;

            // If even after the final jump we can't reach val_v, it's unreachable
            if (unique_vals[idx_u] < val_v) {
                answer.push_back(-1);
            } else {
                answer.push_back(steps);
            }
        }

        return answer;
    }
};