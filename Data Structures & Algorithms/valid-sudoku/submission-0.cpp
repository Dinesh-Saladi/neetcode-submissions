class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<int>st;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        for(int j=0;j<9;j++){
            set<int>st;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<int>st;
                for(int l=i;l<i+3;l++){
                    for(int m=j;m<j+3;m++){
                        if(board[l][m] == '.') continue;
                        if(st.count(board[l][m])) return false;
                        st.insert(board[l][m]);
                    }
                }
            }
        }
        return true;
    }
};
