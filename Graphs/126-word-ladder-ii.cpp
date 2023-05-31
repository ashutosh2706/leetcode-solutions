class Solution {
private:
void dfs(string word, unordered_map<string,int> &map, vector<string> v, vector<vector<string>> &res, string &start) {
    if(word == start) {
        v.push_back(start);
        reverse(begin(v), end(v));
        res.push_back(v);
        reverse(begin(v),end(v));
        v.pop_back();
        return;
    }
    v.push_back(word);
    string orig = word;
    for(int ind=0; ind<word.length(); ind++) {
        word=orig;
        for(char c='a'; c<='z'; c++) {
            word[ind] = c;
            if(map.count(word) and map[word] < map[orig]) {

                dfs(word,map,v,res,start);

            }
        }
    }
    v.pop_back();
}
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& list) {
    // bfs+backtracking
    unordered_set<string> words(list.begin(), list.end());
    if(words.count(end) == 0) return vector<vector<string>>{};
    words.erase(start);
    queue<string> q;
    unordered_map<string,int> map;
    q.push(start);
    bool f=0;
    map[start] = 0;
    while(!q.empty()) {
        int sz=q.size();
        while(sz--) {
            string word = q.front(),orig; q.pop();
            orig = word;
            if(word == end) { f=1; break; }

            for(int ind=0; ind<word.length(); ind++) {
                string word=orig;
                for(char c='a'; c<='z'; c++) {
                    word[ind] = c;
                    if(words.count(word)) {
                        q.push(word);
                        words.erase(word);
                        map[word] = map[orig]+1;
                    }
                }
            }
        }
        if(f) break;
    }

    vector<vector<string>> res;
    dfs(end,map,{},res,start);
    return res;
    }
};