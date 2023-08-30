class Solution {
private:
vector<long> used, nums; 
void solve(int ind, string &pattern, int lo, int hi, long num) {

    if(!nums.empty()) return;

    if(ind > pattern.length()) {
        nums.push_back(num);
        return;
    }
    for(int x=lo; x<=hi; ++x) {

        if(!used[x]) {
            used[x] = 1;
            num = (num*10) + x;
            if(pattern[ind] == 'I') {
                solve(ind+1, pattern, x+1, 9, num);
            } else {
                solve(ind+1, pattern, 1, x-1, num);
            }
            used[x] = 0;
            num -= x;
            num /= 10;
        }
    }
}
public:
    string smallestNumber(string &pattern) {
        used.resize(10);
        solve(0, pattern, 1, 9, 0);
        return to_string(nums[0]);
    }
};