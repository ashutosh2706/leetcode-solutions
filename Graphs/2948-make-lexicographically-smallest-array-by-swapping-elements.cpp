class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    
        map<int, int> par, cnt;
        map<int, map<int, int>> comp;

        for(int i=0; i<nums.size(); ++i) {
            par[nums[i]] = nums[i];
            comp[nums[i]][nums[i]]++;
            cnt[nums[i]]++;
        }

        for(auto it = ++begin(cnt); it != end(cnt); ++it) {
            int c = it->first, p = (prev(it))->first;
            if(c-p <= limit) {
                par[c] = par[p];
                comp[par[c]][c] = cnt[c];
            }
        }

        for(int i=0; i<nums.size(); ++i) {
            int p = par[nums[i]];
            

            int t = begin(comp[p])->first;
            nums[i] = t;
            if(--comp[p][t] == 0) comp[p].erase(t);
        }
        return nums;
    }
};
