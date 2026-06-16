class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int m = n/2;
        int l = -1, r = n1-1;
        while(l<=r){
            int i = l + (r-l)/2;
            int j = m - i - 2;

            int l1 = ((i>=0 && i<n1) ? nums1[i] : INT_MIN);
            int r1 = ((i+1>=0 && i+1<n1) ? nums1[i+1] : INT_MAX);
            int l2 = ((j>=0 && j<n2) ? nums2[j] : INT_MIN);
            int r2 = ((j+1>=0 && j+1<n2) ? nums2[j+1] : INT_MAX);

            if(l1 <= r2 && l2 <= r1){
                if(n&1) return min(r1, r2);
                else return (double)(max(l1, l2) + min(r1, r2)) / 2;
            }else if(l1 > r2) r = i-1;
            else l = i+1; 
        }
        return -1;
    }
};
