class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0)
            return {};
        int rank = 1;
        vector<int> backup(arr);
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        mp[arr[0]] = rank;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] < arr[i]) {

                rank++;
            }
            mp[arr[i]] = rank;
        }

        for (int i = 0; i < arr.size(); i++) {
            backup[i] = mp[backup[i]];
        }
        // else if(arr[i+1] == arr[i])
        // {
        //     mp[arr[i]] = rank;
        // }

        return backup;
    }
};