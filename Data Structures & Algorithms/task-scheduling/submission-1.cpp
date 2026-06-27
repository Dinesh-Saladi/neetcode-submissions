class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt = 0;
        map<char, int>mp;
        for(auto x : tasks) mp[x]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>>pq;
        priority_queue<pair<int, char>>pq1;
        for(auto [f,s] : mp) pq.push({1, f});
        while(mp.size()){
            cnt = cnt+1;
            if(pq1.size() == 0) cnt = pq.top().first;
            while(pq.size() && pq.top().first == cnt) {
                pq1.push({mp[pq.top().second], pq.top().second});
                pq.pop();
            }
            pair<int, char>p = pq1.top();
            pq1.pop();
            mp[p.second]--;
            if(!mp[p.second]) mp.erase(p.second);
            else pq.push({cnt+n+1, p.second});
        }
        return cnt;
    }
};
