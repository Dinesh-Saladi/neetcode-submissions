class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<float, float>>a(n);
        for(int i=0;i<n;i++){
            a[i] = {position[i], speed[i]};
        }
        sort(a.begin(), a.end());
        float maxi = 0;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            float time = (target-a[i].first)/a[i].second;
            if(maxi < time) ans++;
            maxi = max(maxi, time);
        }
        return ans;
    }
};
