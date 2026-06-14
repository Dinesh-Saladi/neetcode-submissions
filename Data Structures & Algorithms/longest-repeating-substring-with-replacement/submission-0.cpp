class Solution {
public:
    int maxi(map<char, int>&mp){
        int maxi = 0;
        for(auto [f,s]:mp) maxi = max(maxi, s);
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        map<char, int>mp;
        int ans = 0;
        int l = 0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(maxi(mp)+k < r-l+1){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
