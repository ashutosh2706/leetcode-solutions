class Solution {
private:
int possible(vector<int> &nums, int mid, int k) {
    int sum = 0, partitions = 0;
    for(auto &i : nums) {
        if(sum + i> mid) {
            sum = i;
            partitions++;
        }else sum += i;
        if(partitions > k) return 0;
    }
    return partitions + 1 <= k;
}
public:
    int splitArray(vector<int>& nums, int k) {

    int l = *max_element(begin(nums), end(nums));
    int r = accumulate(nums.begin(), nums.end(), 0);
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(possible(nums, mid, k)) r = mid - 1;
        else l = mid + 1;
    }
    return l;       
    }
};