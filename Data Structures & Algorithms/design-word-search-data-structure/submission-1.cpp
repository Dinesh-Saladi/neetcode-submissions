#include<bits/stdc++.h>

struct Node{
    bool is;
    Node* a[26];
    Node(){
        is = false;
        memset(a, NULL, sizeof(a));
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(auto c : word){
            int cc = c - 'a';
            if(temp->a[cc]){
                temp = temp->a[cc];
            }else{
                temp->a[cc] = new Node();
                temp = temp->a[cc];
            }
        }
        temp->is = true;
    }
    
    bool search(string word) {
        bool ans = false;
        queue<Node*>q;
        q.push(root);
        for(auto c : word){
            int size = q.size();
            if(c == '.'){
                for(int i=0;i<size;i++){
                    Node* temp = q.front();
                    q.pop();
                    for(int i=0;i<26;i++){
                        if(temp->a[i]) q.push(temp->a[i]);
                    }
                }
            }else{
                for(int i=0;i<size;i++){
                    Node* temp = q.front();
                    q.pop();
                    if(temp->a[c-'a']) q.push(temp->a[c-'a']);
                }
            }
        }
        while(q.size()){
            Node* temp = q.front();
            q.pop();
            if(temp->is) return true;
        }
        return false;
    }
};
