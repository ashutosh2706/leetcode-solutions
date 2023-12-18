class Solution {
public:
    unordered_map<string, vector<string>> ing;
    unordered_set<string> vis, supp;

    int check(string &s) {
        if(supp.count(s)) return 1;
        if(ing.count(s) == 0) return 0;

        if(vis.count(s)) return 0; 
        vis.insert(s);
        
        bool can_make=1;
        for(auto &i : ing[s]) {
            can_make = can_make and check(i);
        }
        if(can_make) supp.insert(s);
        return can_make;
        
}
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        for(int i=0; i<recipes.size(); ++i) {
            ing[recipes[i]] = ingredients[i];
        }
        for(auto &s : supplies) supp.insert(s);

        for(auto &s : recipes) if(check(s)) res.push_back(s);
        return res;
    }
};