class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string res = "";
        while(!pq.empty()) {
            int count = pq.top().first; 
            char ch = pq.top().second; 
            pq.pop();
            if(res.length() > 1 and (res.back() == res[res.length()-2]) and (res.back() == ch)) {
                if(pq.empty()) break;
                auto p2 = pq.top(); pq.pop();
                res += p2.second;
                if(p2.first - 1 > 0) 
                    pq.push({p2.first - 1, p2.second});
            } else {
                res += ch;
                count--;
            }
            if(count) 
                pq.push({count, ch});
        }

        return res;
    }
};