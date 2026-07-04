class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        map<int, int>mp;
        vector<set<int>>adj(26);
        for(auto x : words){
            for(auto c : x) mp[c-'a']++;
        }
        for(int i=1;i<n;i++){
            bool check = false;
            for(int j=0;j<words[i].length()&&j<words[i-1].length();j++){
                if(words[i-1][j] != words[i][j]){
                    adj[words[i-1][j]-'a'].insert(words[i][j]-'a');
                    check = true;
                    break;
                }
            }
            if(!check && words[i-1].length() > words[i].length()) return "";
        }
        vector<int>ind(26, 0);
        for(int i=0;i<26;i++) {
            for(auto x : adj[i]) ind[x]++;
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(!ind[i] && mp.find(i) != mp.end()) q.push(i);
        }
        string ans = "";
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            cnt++;
            q.pop();
            ans += char(u+'a');
            for(auto v : adj[u]){
                ind[v]--;
                if(!ind[v]) q.push(v);
            }
        }
        return cnt == mp.size() ? ans : "";
    }
};
