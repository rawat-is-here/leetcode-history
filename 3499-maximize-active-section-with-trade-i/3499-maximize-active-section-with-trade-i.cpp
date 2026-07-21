class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;
        int bestGain = 0;

        int leftZeroBlock = 0;
        int currentZeroBlock = 0;
        bool crossedOneBlock = false;

        for (char ch : s) {
            if (ch == '1') {
                originalOnes++;

                if (currentZeroBlock > 0) {
                    leftZeroBlock = currentZeroBlock;
                    currentZeroBlock = 0;
                }

                if (leftZeroBlock > 0) {
                    crossedOneBlock = true;
                }
            } else {
                if (crossedOneBlock) {
                    currentZeroBlock++;

                    bestGain = max(
                        bestGain,
                        leftZeroBlock + currentZeroBlock
                    );
                } else {
                    currentZeroBlock++;
                }
            }
        }

        return originalOnes + bestGain;
    }
};//