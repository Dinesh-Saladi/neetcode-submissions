#include<bits/stdc++.h>

struct Node{
    bool is;
    Node* a[26];
    Node(){
        is = false;
        memset(a, 0, sizeof(a));
    }
};

class Solution {
public:
    void go(int i, int j, string &s, Node* root, vector<vector<char>>& board, set<string>&st, vector<vector<bool>>&vis){
        if(i == -1 || j == -1 || i == board.size() || j == board[0].size()) return;
        if(vis[i][j]) return ;
        int c = board[i][j] - 'a';
        if(!root->a[c]) return ;
        vis[i][j] = true;
        s += board[i][j];
        root = root->a[c];
        if(root->is) st.insert(s);
        go(i+1, j, s, root, board, st, vis);
        go(i-1, j, s, root, board, st, vis);
        go(i, j+1, s, root, board, st, vis);
        go(i, j-1, s, root, board, st, vis);
        vis[i][j] = false;
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(auto w : words){
            Node* temp = root;
            for(auto c : w){
                int cc = c - 'a';
                if(temp->a[cc]) temp = temp->a[cc];
                else{
                    temp->a[cc] = new Node();
                    temp = temp->a[cc];
                }
            }
            temp->is = true;
        }
        set<string>st;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<bool>>vis(m, vector<bool>(n, false));
                string s = "";
                go(i, j, s, root, board, st, vis);
            }
        }
        vector<string>ans;
        for(auto x : st) ans.push_back(x);
        return ans;
    }
};
