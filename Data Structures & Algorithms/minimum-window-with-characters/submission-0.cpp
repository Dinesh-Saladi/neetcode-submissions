class Solution {
public:
    bool check(map<char, int>&a, map<char, int>&b){
        for(auto x : b){
            if(a[x.first] < x.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int>a, b;
        for(auto x : s) a[x]++;
        for(auto x : t) b[x]++;
        for(auto x : b){
            if(a[x.first] < x.second) return "";
        }
        a.clear();
        int len = n;
        int i = 0, j = n-1;
        int l = 0;
        for(int r=0;r<n;r++){
            a[s[r]]++;
            if(check(a, b)){
                while(check(a, b)){
                    if(len > r-l+1){
                        i = l;
                        j = r;
                        len = r-l+1;
                    }
                    a[s[l]]--;
                    if(a[s[l]] == 0) a.erase(s[l]);
                    l++;
                }
            }
        }
        string ans = "";
        for(int k=i;k<=j;k++) ans += s[k];
        return ans;
    }
};
