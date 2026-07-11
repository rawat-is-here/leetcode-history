/*This is only written for streak, I dont know anything*/
class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        // Step 1: Build the adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        // Step 2: Traverse the graph to find connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int edgeCount = 0;

                // BFS to explore the current component
                std::queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    vertexCount++;
                    
                    // Sum up the degrees of all vertices in this component
                    edgeCount += adj[curr].size();

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Since it's an undirected graph, every edge within the component 
                // is counted twice (once from each endpoint). 
                // For a complete graph, total degree sum must equal V * (V - 1)
                if (edgeCount == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }

        return completeComponentsCount;
    }
};