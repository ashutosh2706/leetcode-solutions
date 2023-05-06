class Solution {
private:
vector<string> search(vector<string> &prod, string &s, int pos) {

    int n = prod.size();
    int l = 0, r = n-1;
    string str = s.substr(0,pos+1);
    while(l <= r) {
        if(prod[l].substr(0, pos+1) < str) l++;
        else if(prod[r].substr(0, pos+1) > str) r--;
        else break;
    }
    vector<string> res;
    int cnt = 0;
    while(cnt < 3 and l <= r) {
        res.push_back(prod[l++]);
        cnt++;
    }
    return res;
}
public:
    vector<vector<string>> suggestedProducts(vector<string>& prod, string word) {
        sort(begin(prod), end(prod));   
        vector<vector<string>> suggestion;
        for(int i=0; i<word.length(); i++) suggestion.push_back(search(prod, word, i));
        return suggestion;
    }
};