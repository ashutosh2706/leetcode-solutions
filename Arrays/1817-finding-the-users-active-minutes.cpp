class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    set<vector<int>> st(begin(logs),end(logs));
    vector<int> cnt(k);
    int c = 0, p = -1;
    for(auto &a:st) {
        if(p == -1) {
            p = a[0];
            c = 1;
            continue;
        }
        if(p == a[0]) c++;
        else {
            cnt[c-1]++;
            p = a[0];
            c=1;
        }
    }
    cnt[c-1]++;
    return cnt;
    }
};