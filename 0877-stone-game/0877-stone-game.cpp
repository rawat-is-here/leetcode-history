#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool stoneGame(std::vector<int>& piles) {
        int n = piles.size();
        std::vector<int> dp = piles;
        
        for (int lambaai = 2; lambaai <= n; ++lambaai) {
        for (int i = 0; i <= n - lambaai; ++i) {
        int j = i + lambaai - 1;
            dp[i] = std::max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }
        
        return dp[0] > 0;
    }
};
