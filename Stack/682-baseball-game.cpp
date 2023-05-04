class Solution {
public:
    int calPoints(vector<string>& op) {
        
        vector<int> S;
        for(auto &s : op) {
            if(s == "+") {
                int n = S.size()-1;
                S.push_back(S[n] + S[n-1]);
            } else if(s == "C") S.pop_back();
            else if(s == "D") {
                S.push_back(2 * S.back());
            } else {
                S.push_back(stoi(s));
            }
        }
        return accumulate(begin(S), end(S), 0);
    } 
};