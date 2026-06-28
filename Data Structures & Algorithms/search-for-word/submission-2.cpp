class Solution {
public:
    bool go(int i, int j, int m, int n, string &s, string &word, vector<vector<char>>& board, vector<vector<bool>>&vis){
        if(i == -1 || j == -1 || i == m || j == n) return false;
        if(vis[i][j]) return false;
        s += board[i][j];
        if(s.back() != word[s.length()-1]){
            s.pop_back();
            return false;
        }
        if(s == word) {
            s.pop_back();
            return true;
        }
        vis[i][j] = true;
        bool ans = false;
        ans = ans || go(i+1, j, m, n, s, word, board, vis);
        ans = ans || go(i, j+1, m, n, s, word, board, vis);
        ans = ans || go(i-1, j, m, n, s, word, board, vis);
        ans = ans || go(i, j-1, m, n, s, word, board, vis);
        s.pop_back();
        vis[i][j] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] != word[0]) continue;
                vector<vector<bool>>vis(m, vector<bool>(n, false));
                string s = "";
                if(go(i, j, m, n, s, word, board, vis)) return true;
            }
        }
        return false;
    }
};
