/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
int dfs(int id, unordered_map<int, int> &m1, unordered_map<int, vector<int>> &m2) {
    int ans = m1[id];
    for(auto &p : m2[id]) {
        ans += dfs(p, m1, m2);
    }
    return ans;
}
public:
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map<int,int> m1;
        unordered_map<int, vector<int>> m2;
        for(auto &p : emp) {
            m1[p->id] = p->importance;
            for(auto i : p->subordinates) {
                m2[p->id].push_back(i);
            }
        }
        
        return dfs(id, m1, m2);

    }
};