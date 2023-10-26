/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> nums;

    void flat(vector<NestedInteger> &t, vector<int> &nums) {
        for(auto &a : t) {
            if(a.isInteger()) nums.push_back(a.getInteger());
            else flat(a.getList(), nums);
        }
    }

    int p = 0;
    NestedIterator(vector<NestedInteger> &list) {
        for(auto &t : list) {
            if(t.isInteger()) {
                nums.emplace_back(t.getInteger());
            } else 
                flat(t.getList(), nums);
        }
    }
    
    int next() {
        return nums[p++];
    }
    
    bool hasNext() {
        return p < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */