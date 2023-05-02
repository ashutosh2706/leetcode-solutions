class Solution {
private:
int signfunc(vector<int> &nums) {
    int c = 0, z = 0;
    for(auto &i : nums) {
        if(i == 0) return 0;
        if(i < 0) c++;
    }
    return c % 2 == 0 ? 1 : -1;
}
public:
    int arraySign(vector<int>& nums) {
        return signfunc(nums);
    }
};