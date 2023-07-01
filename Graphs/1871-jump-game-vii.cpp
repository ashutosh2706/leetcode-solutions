class Solution {
public:
    bool canReach(string s, int minj, int maxj) {
        
        if(s.back() == '1') return 0;
        int N = s.length(), far_ind = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int ind = q.front(); q.pop();
            if(ind == N-1) return 1;
            for(int i = max(far_ind+1, ind+minj); i <= ind + maxj; i++) {
                if(i >= N) break;
                if(s[i] == '0') q.push(i);
                far_ind = max(far_ind, i);
            }
        }
        return 0;
    }
};