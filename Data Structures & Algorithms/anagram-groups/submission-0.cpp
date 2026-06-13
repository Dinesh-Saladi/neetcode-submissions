class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>mp;
        for(auto x : strs){
            string s = x;
            sort(x.begin(), x.end());
            mp[x].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto [f, s]: mp) ans.push_back(s);
        return ans;
    }
};
