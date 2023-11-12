class Solution {
public:
    int count(vector<string>& t) {
        sort(begin(t), end(t), [](string &a, string &b) {
            return stoi(a) < stoi(b);
        });

        int n = t.size();
        for(int i=0; i<n; ++i) {
            int cnt = 1, hr = stoi(t[i].substr(0,2)), min = stoi(t[i].substr(2));
            for(int j=i+1; j<n; ++j) {

                int h = stoi(t[j].substr(0,2)), m = stoi(t[j].substr(2));
                if(hr == 23) {
                    if(h == hr and m <= 59) cnt++;

                } else {
                    if(h == hr or (h == (hr+1) and m < min)) cnt++;
                }
            }   
            if(cnt >= 3) return 1;
        }
        return 0;
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        
        unordered_map<string, vector<string>> mp;
        for(auto &a : at) mp[a[0]].push_back(a[1]);
        vector<string> res;
        for(auto &[k,v] : mp) if(count(v)) res.push_back(k);
        return res;
        
    }
};