class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0, right = matrix.size()-1, mid;
    mid = (left+right)/2;
    while(left < right && !(matrix[mid].front() <= target && target <= matrix[mid].back())) {
        if(target > matrix[mid].back()) left = mid+1;
        else if(target < matrix[mid].front()) right = mid-1;
        else break;
        mid = (left+right)/2;
    }
    left = 0, right = matrix[mid].size()-1;
    int mmid = (left+right)/2;
    while(left < right && matrix[mid][mmid]!=target) {
        if(target > matrix[mid][mmid]) left = mmid+1;
        else right = mmid-1;
        mmid = (left+right)/2;
    }
    return matrix[mid][mmid]==target;
    }
};