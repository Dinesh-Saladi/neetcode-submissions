class Solution {
public:
    void go(int ind, string&s, vector<string>&v, vector<vector<string>>&ans){
        if(ind == s.length()){
            ans.push_back(v);
            return ;
        }
        string a = "", b = "";
        for(int i=ind;i<s.length();i++){
            a += s[i];
            b = a;
            reverse(b.begin(), b.end());
            if(a == b){
                v.push_back(a);
                go(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        go(0, s, v, ans);
        return ans;
    }
};
