class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int>mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]-1]){
                mp[nums[i]] = mp[nums[i]-1]+1;
            }else if(!mp[nums[i]]){
                mp[nums[i]] = 1;
            }
            // cout<<mp[nums[i]]<<endl;
            ans = max(ans, mp[nums[i]]);
        }
        return ans;
    }
};
