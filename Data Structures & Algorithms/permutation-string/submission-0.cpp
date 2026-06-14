class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        int n1 = s1.length(), n2 = s2.length();
        vector<int>v(26, 0), a(26, 0);
        for(auto x : s1) v[x-'a']++;
        for(int i=0;i<n1;i++){
            a[s2[i]-'a']++;
        }
        if(a==v) return true;
        for(int i=n1;i<n2;i++){
            a[s2[i-n1]-'a']--;
            a[s2[i]-'a']++;
            if(a==v) return true;
        }
        return false;
    }
};
