class Solution {
private:
string inc(string s, int ind) {
    s[ind] == '9' ? s[ind] = '0' : s[ind] += 1;
    return s;
}
string dec(string s, int ind) {
    s[ind] == '0' ? s[ind] = '9' : s[ind] -= 1;
    return s;
}
public:
    int openLock(vector<string>& deadends, string target) {
        
        set<string> dead,vis;
        for(auto &s:deadends) dead.insert(s);
        if(dead.count("0000")) return -1;
        queue<string> q;
        q.push("0000"); vis.insert("0000");
        int steps=0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string s = q.front(); q.pop();
                if(s == target) return steps;
                for(int i=0; i<4; i++) {
                    string x = inc(s, i), y = dec(s, i);
                    if(dead.count(x) == 0 and vis.count(x) == 0) {
                        vis.insert(x);
                        q.push(x);
                    }
                    if(dead.count(y) == 0 and vis.count(y) == 0) {
                        vis.insert(y);
                        q.push(y);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};