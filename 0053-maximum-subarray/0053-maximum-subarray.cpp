class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int maxsum = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            current_sum = max(nums[i], nums[i]+current_sum); //jo mujhe add karke milega, wo better hai, ya fir mai fresh start karu
            maxsum = max(current_sum, maxsum);
        }
        return maxsum;
    }
};
// This choice means:
// Sometimes, you have to take a hit (a negative number) to reach a massive jackpot on the other side.
/*and did you gain anything from the jackpot? or you are just keep getting hit is maintained by our savour maxsum

You have perfectly described the dynamic duo of Kadane's algorithm! Calling max_sum the saviour is 100% accurate.

Think of Kadane’s algorithm as a two-person team inside the loop:

current_sum is the Adventurer: It runs forward, taking risks, collecting jackpots, and bravely swallowing negative numbers to see if there's gold on the other side.

max_sum is the Vault: It sits safely in the back. Every time the Adventurer hits a new all-time high score, the Vault locks that value in. If the Adventurer gets absolutely crushed by a massive negative number on the next step, the Vault doesn't care—your jackpot is already safe inside.*/
/*
Start at 4. current_sum = 4.

Next element is -1.

Kadane asks: Is it better to start fresh at -1, or keep the streak alive at 3?

3 is better than -1, so Kadane swallows the bad news and keeps moving with current_sum = 3.

Next element is 5.

We add it to our running streak: 3 + 5 = 8. current_sum = 8.

The loop ends. The highest recorded sum is 8 (from the subarray [4, -1, 5]).
*/