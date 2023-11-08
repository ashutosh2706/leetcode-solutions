class DSU {
    public:
    vector<int> par, size;
    DSU(int sz) {
        size.resize(sz,1);
        for(int i=0; i<sz; ++i) par.push_back(i);
    }

    // path compression
    int find(int u) {
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    // union by size
    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if(size[u] > size[v]) {
            par[v] = u;
            size[u] += size[v];
        } else {
            par[u] = v;
            size[v] += size[u];
        }
    }

    int count() {
        int sz = 1;
        for(auto &a : size) sz = max(sz, a);
        return sz;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        DSU obj(nums.size());
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); ++i) {
            if(mp.count(nums[i])) continue;

            if(mp.find(nums[i] - 1) != end(mp)) 
                obj.Union(mp[nums[i]-1], i);
            if(mp.find(nums[i] + 1) != end(mp))
                obj.Union(mp[nums[i]+1], i);

            mp[nums[i]] = i;
        }

        return obj.count();

    }
};