class Solution {
public:
    int minimumIndex(vector<int>& nums) {
    unordered_map<int,int> m1,m2;
    int N = nums.size(), dom;
    for(auto&a : nums) {
        m1[a]++;
        if(m1[a] * 2 > N) dom = a;
    }
    priority_queue<pair<int,int>> pq;
    for(auto &p : m1) pq.push({p.second, p.first});
    
    int maxi = 0;
    for(int i=0; i<N; i++) {
        int a = nums[i];
        m2[a]++;
        m1[a]--;

        while(pq.top().first != m1[pq.top().second]) {
            auto pp = pq.top(); pq.pop();
            pp.first = m1[pp.second];
            pq.push(pp);
        }
        

        int d1 = -1, d2 = -1;
        if(m2[a] >= maxi) {
            maxi = m2[a];
            if(maxi * 2 > (i+1) and a == dom) d1 = a; 
        }

        if(d1 == -1) continue;
        if(pq.top().second == dom and (pq.top().first*2) > (N - (i + 1))) d2 = pq.top().second;
        if(d2 == -1) continue;

        return i;

    }
        return -1;
    }
};