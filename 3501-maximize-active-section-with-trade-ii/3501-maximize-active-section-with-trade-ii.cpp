/*only for challenge purpose i dont know anythign about the algorithm*/
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
    int n = s.length();
        int total_ones = 0;
        vector<pair<int, int>> B;
        int start = -1;
        
        // Step 1: Identify all contiguous 0-blocks in the string
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                total_ones++;
                if (start != -1) {
                    B.push_back({start, i - 1});
                    start = -1;
                }
            } else {
                if (start == -1) {
                    start = i;
                }
            }
        }
        if (start != -1) {
            B.push_back({start, n - 1});
        }
        
        int m = B.size();
        vector<int> S_vec(m), E_vec(m);
        for (int i = 0; i < m; ++i) {
            S_vec[i] = B[i].first;
            E_vec[i] = B[i].second;
        }
        
        // Step 2: Build Sparse Table (RMQ) for consecutive full-block pairs
        int LOG = 0;
        while ((1 << LOG) <= m) {
            LOG++;
        }
        
        vector<vector<int>> st;
        if (m > 1) {
            st.assign(m - 1, vector<int>(LOG, 0));
            for (int i = 0; i < m - 1; ++i) {
                st[i][0] = (B[i].second - B[i].first + 1) + (B[i+1].second - B[i+1].first + 1);
            }
            for (int j = 1; j < LOG; ++j) {
                for (int i = 0; i + (1 << j) <= m - 1; ++i) {
                    st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
        }
        
        auto query_st = [&](int L_idx, int R_idx) {
            if (L_idx > R_idx) return 0;
            int j = 31 - __builtin_clz(R_idx - L_idx + 1);
            return max(st[L_idx][j], st[R_idx - (1 << j) + 1][j]);
        };
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        // Step 3: Process queries
        for (auto& q_arr : queries) {
            int L = q_arr[0];
            int R = q_arr[1];
            
            if (m == 0) {
                answer.push_back(total_ones);
                continue;
            }
            
            // Binary search to find intersecting block ranges [p, q]
            auto it_p = lower_bound(E_vec.begin(), E_vec.end(), L);
            int p = (it_p == E_vec.end()) ? -1 : it_p - E_vec.begin();
            
            auto it_q = upper_bound(S_vec.begin(), S_vec.end(), R);
            int q = it_q - S_vec.begin() - 1;
            
            if (p == -1 || q == -1 || p > q) {
                answer.push_back(total_ones);       // No 0-blocks inside substring
                continue;
            }
            if (p == q) {
                answer.push_back(total_ones);       // Only 1 0-block inside substring (No Trade setup possible)
                continue;
            }
            
            // Constrained lengths cut out by L & R borders
            int w_p = min(R, B[p].second) - max(L, B[p].first) + 1;
            int w_q = min(R, B[q].second) - max(L, B[q].first) + 1;
            
            if (p + 1 == q) {
                answer.push_back(total_ones + w_p + w_q);
                continue;
            }
            
            int max_gain = 0;
            
            // Verify Left Edge cut merging with its Right full neighbor
            int len_p1 = B[p+1].second - B[p+1].first + 1;
            max_gain = max(max_gain, w_p + len_p1);
            
            // Verify Right Edge cut merging with its Left full neighbor
            int len_qm1 = B[q-1].second - B[q-1].first + 1;
            max_gain = max(max_gain, len_qm1 + w_q);
            
            // Account for any internal untouched sets via Sparse Table checks 
            if (p + 1 <= q - 2) {
                max_gain = max(max_gain, query_st(p + 1, q - 2));
            }
            
            answer.push_back(total_ones + max_gain);
        }
        
        return answer;
    }
};