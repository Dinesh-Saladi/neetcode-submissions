class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for(auto x : prices) {
            mini = min(mini, x);
            ans = max(ans, x-mini);
        }
        return ans;
    }
};
