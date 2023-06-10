class Solution {
private:
bool isPossible(vector<int> &nums, int balls, int force) {
    int last = -1;
    for(int i=0; i<nums.size() and balls; i++) {
        if(last == -1) {
            balls--;
            last = i;
            continue;
        }
        if(nums[i] - nums[last] >= force) {
            balls--;
            last = i;
        }
    }
    return balls == 0;
}
public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int lo = 1, hi = 1e9, mid;
        while(lo <= hi) {
            mid = lo+(hi-lo)/2;

            if(isPossible(position, m, mid)) lo = mid+1;
            else hi = mid-1;
        }
        return hi;
    }
};