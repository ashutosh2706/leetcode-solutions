class Solution {
private:
int possible(vector<int> &nums, int cap, int days) {
    
    int sum = 0, day = 1;
    for(auto &e : nums) {
        if(sum + e > cap) {
            sum = e;
            day++;
        }else sum += e;
        if(day > days) return 0;
    }
    return day <= days;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
    int l = *max_element(begin(weights), end(weights));
    int r = accumulate(begin(weights), end(weights), 0);
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(possible(weights, mid, days)) r = mid-1;
        else l = mid+1;
    }
    return l;
    }
};