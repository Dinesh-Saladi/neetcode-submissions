class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == -nums[i]){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int nl = nums[l], nr = nums[r];
                    while(l < r && nums[l] == nl && nums[r] == nr) l++, r--; 
                }else if(sum < -nums[i]){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};
