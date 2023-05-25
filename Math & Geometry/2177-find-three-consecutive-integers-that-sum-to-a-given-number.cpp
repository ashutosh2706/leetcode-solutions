class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3 != 0) return vector<long long>{};
        long long rem = num / 3;
        return vector<long long>{rem-1,rem,rem+1};
    }
};