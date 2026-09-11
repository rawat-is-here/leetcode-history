class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Count available frequency of each digit (0 to 9)
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int validCount = 0;

        // Step 2: Check every 3-digit even number from 100 to 998
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;         // hundreds place (1-9)
            int d2 = (num / 10) % 10;   // tens place (0-9)
            int d3 = num % 10;          // units place (even)

            // Track how many copies of each digit this specific number needs
            vector<int> needed(10, 0);
            needed[d1]++;
            needed[d2]++;
            needed[d3]++;

            // Step 3: Verify that the input has enough copies of each digit
            if (count[d1] >= needed[d1] &&
                count[d2] >= needed[d2] &&
                count[d3] >= needed[d3]) {
                validCount++;
            }
        }

        return validCount;
    }
};