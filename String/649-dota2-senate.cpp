class Solution {
public:
    string predictPartyVictory(string s) {

    int R = 0, D = 0, n = s.length();
    queue<char> q;
    for(auto &c : s) q.push(c);
    while(!q.empty()) {
        int sz = q.size();
        int b1 = 1, b2 = 1;
        while(sz--) {
            auto ch = q.front(); q.pop();
            if(ch == 'R') {
                if(R == 0) {
                    b1 = 0;
                    D++;
                    q.push('R');
                } else R--;
            }else {
                if(D == 0) {
                    b2 = 0;
                    R++;
                    q.push('D');
                } else D--;
            }    
        }
        if(b1 || b2) {
            if(q.front() == 'R') return "Radiant";
            return "Dire";
        }
    }
    return "";
    }
};