class Solution {
private:
    bool is_palin(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        return r==s;
    }
    
    void func(string s, int index, vector<string> ds, vector<vector<string>>& ans) {

    if(index==s.length()) {
        ans.push_back(ds);
        return;
    }
    
    for(int i=index; i<s.length(); i++) {
        string sub=s.substr(index,(i-index)+1);
        if(is_palin(sub)) {
            ds.push_back(sub);
            func(s,i+1,ds,ans);
            ds.pop_back();
        }
    }

}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        func(s,0,{},ans);
        return ans;
    }
};