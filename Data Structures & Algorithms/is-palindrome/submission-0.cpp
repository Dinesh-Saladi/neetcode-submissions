class Solution {
public:
    bool isal(char c){
        return (c >= 'A' && c <= 'Z');
    }
    bool isaln(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        string l = "";
        for(auto x : s) {
            if(isaln(x)) {
                if(isal(x)){
                    l += char(x+'a'-'A');
                }else{
                    l += x;
                }
            }
        }
        string m = l;
        reverse(m.begin(), m.end());
        return l == m;
    }
};
