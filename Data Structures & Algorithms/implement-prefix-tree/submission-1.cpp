struct Node{
    bool is;
    Node* a[26];
    Node(){
        is = false;
        for(int i=0;i<26;i++) a[i] = NULL;
    };
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* temp = root;
        for(auto c : word){
            int cc = c - 'a';
            if(temp->a[cc]){
                temp = temp->a[cc];
            }else return false;
        }
        return temp->is;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto c : prefix){
            int cc = c - 'a';
            if(temp->a[cc]){
                temp = temp->a[cc];
            }else return false;
        }
        return true;
    }
};
