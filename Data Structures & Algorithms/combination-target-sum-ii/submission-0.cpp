class Solution {
public:
    void go(int ind, vector<pair<int, int>>&nums, int sum, int target, vector<int>&v, vector<vector<int>>&ans){
        if(ind == nums.size()) return;
        go(ind+1, nums, sum, target, v, ans);
        int cnt = 0;
        for(int i=0;i<nums[ind].second;i++){
            if(sum+nums[ind].first > target) break;
            cnt++;
            v.push_back(nums[ind].first);
            sum += nums[ind].first;
            if(sum == target) ans.push_back(v);
            else go(ind+1, nums, sum, target, v, ans);
        }
        while(cnt--) v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        map<int, int>mp;
        for(auto x : candidates) mp[x]++;
        vector<pair<int, int>>nums;
        for(auto x : mp) nums.push_back(x);
        go(0, nums, 0, target, v, ans);
        return ans;
    }
};
