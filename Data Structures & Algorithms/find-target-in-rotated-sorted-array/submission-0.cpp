class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        if(nums.back() < target) l = 0, r = k-1;
        else l = k, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};
