class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_map<long long,int> map;
        long long sum = 0, v = 1, i = 0;
        while(i < n) {
            if(!map.count(target-v)) {
                map[v]++;
                sum += v;
                i++;
            }
            v++;
        }
        return sum;
    }
};