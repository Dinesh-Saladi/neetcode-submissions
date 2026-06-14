class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26, 0), b(26, 0);
        for(auto x : s) a[x-'a']++;
        for(auto x : t) b[x-'a']++;
        return a == b;
    }
};
