class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int k = 0;
        int l = 0, r = m-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target){
                k = mid;
                l = mid+1;
            }else r = mid-1;
        }
        l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[k][mid] == target) return true;
            else if(matrix[k][mid] > target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
