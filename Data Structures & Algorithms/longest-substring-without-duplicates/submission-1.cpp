class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int>v;
        int l = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            v[s[r]]++;
            while(v[s[r]] == 2){
                v[s[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
