class Solution {
public:
    void go(int ind, vector<int>&nums, int sum, int target, vector<int>&v, vector<vector<int>>&ans){
        if(ind == nums.size()) return;
        go(ind+1, nums, sum, target, v, ans);
        int cnt = 0;
        while(sum+nums[ind] < target){
            v.push_back(nums[ind]);
            sum += nums[ind];
            cnt++;
            go(ind+1, nums, sum, target, v, ans);
        }
        if(sum+nums[ind] == target){
            v.push_back(nums[ind]);
            ans.push_back(v);
            cnt++;
        }
        while(cnt--) v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        go(0, nums, 0, target, v, ans);
        return ans;
    }
};
