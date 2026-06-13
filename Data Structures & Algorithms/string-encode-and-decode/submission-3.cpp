class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto x : strs) ans += to_string(x.length()) + "#" + x;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        int i = 0;
        string w = "";
        while(i < s.length()){
            while(s[i] != '#') w += s[i++];
            i++;
            int c = stoi(w);
            w = "";
            for(int j=0;j<c;j++){
                w += s[i++];
            }
            strs.push_back(w);
            w = "";
        }
        return strs;
    }
};
