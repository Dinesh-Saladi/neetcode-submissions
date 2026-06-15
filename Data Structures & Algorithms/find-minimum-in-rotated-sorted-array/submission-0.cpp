class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int k = 0;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= nums.back()){
                k = mid;
                r = mid-1;
            }else l = mid+1;
        }
        return nums[k];
    }
};
