class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long sum = 0;
        sort(begin(arr),end(arr));
        unordered_map<int,long long> mp;
        for(auto &a : arr) mp[a]++;
        for(int i=1; i<arr.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(arr[i] % arr[j] == 0 and mp.count(arr[i]/arr[j])) {
                    mp[arr[i]] += (mp[arr[j]] * mp[arr[i]/arr[j]]);
                }
            }
        }
        for(auto &[k,v] : mp) {
            sum = (sum + v) % (int)(1e9+7);
        }
        return sum;
    }
};