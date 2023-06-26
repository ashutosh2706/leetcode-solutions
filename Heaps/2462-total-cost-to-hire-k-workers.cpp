class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int candidates) {
        int l = 0, r = nums.size() - 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> f, b;
        while(f.size() < candidates) {
            f.push(make_pair(nums[l], l));
            l++;
        }
        while(b.size() < candidates) {
            b.push(make_pair(nums[r], r));
            r--;
        }
        unordered_set<int> taken;
        long long ans = 0;
        for(int i=0; i<k; i++) {

            while(!f.empty() and taken.count(f.top().second)) f.pop();
            while(!b.empty() and taken.count(b.top().second)) b.pop();
            while(l < nums.size() and f.size() < candidates) {
                if(!taken.count(l)) f.push({nums[l], l});
                l++;
            }
            while(r >= 0 and b.size() < candidates) {
                if(!taken.count(r)) b.push({nums[r], r});
                r--;
            }
            if(f.top() < b.top()) {
                ans += f.top().first;
                taken.insert(f.top().second);
                f.pop();
            } else {
                ans += b.top().first;
                taken.insert(b.top().second);
                b.pop();
            }
        }
        return ans;  
    }
};