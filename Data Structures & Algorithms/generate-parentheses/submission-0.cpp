class Solution {
public:
    void go(int o, int c, string &s, vector<string>&ans){
        if(o>c || o<0 || c<0) return ;
        if(!o && !c){
            ans.push_back(s);
            return ;
        }
        s += "(";
        go(o-1, c, s, ans);
        s.pop_back();
        s += ")";
        go(o, c-1, s, ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>ans;
        go(n, n, s, ans);
        return ans;
    }
};
