class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0)
            return {};
        vector<int> result;
        vector<int> backup(arr);
        sort(arr.begin(), arr.end());
        int k = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[k] != arr[i]) {
                k++;
                arr[k] = arr[i];
            }
        } // till here k will be the size of the unique array
        unordered_map<int, int> mp;
        for (int i = 0; i < k + 1; i++)
            mp[arr[i]] = i + 1;

        for (int i = 0; i < backup.size(); i++) {
            result.push_back(mp[backup[i]]);
        }

        return result;
    }
};