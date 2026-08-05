#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the directed adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: BFS from node k to mark all suspicious methods
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nextNode : adj[curr]) {
                if (!suspicious[nextNode]) {
                    suspicious[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool cannotRemove = false;
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!suspicious[u] && suspicious[v]) {
                cannotRemove = true;
                break;
            }
        }

        // Step 4: Collect remaining methods
        vector<int> remaining;
        if (cannotRemove) {
            // If removal is impossible, return all methods
            for (int i = 0; i < n; ++i) {
                remaining.push_back(i);
            }
        } else {
            // Otherwise, return only non-suspicious methods
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    remaining.push_back(i);
                }
            }
        }

        return remaining;
    }
};