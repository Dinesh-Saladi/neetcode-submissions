class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto x : strs) ans += to_string(x.length()) + " ";
        while(ans.length() < 400) ans += " ";
        for(auto x : strs) ans += x;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        vector<int>len;
        string w = "";
        for(int i=0;i<400;i++){
            if(s[i] == ' ') {
                if(w.length()){
                    len.push_back(stoi(w));
                    w = "";
                }
            }else w += s[i];
        }
        int i = 400;
        for(auto l : len){
            string w = "";
            for(int j=0;j<l;j++, i++){
                w += s[i];
            }
            strs.push_back(w);
        }
        return strs;
    }
};
