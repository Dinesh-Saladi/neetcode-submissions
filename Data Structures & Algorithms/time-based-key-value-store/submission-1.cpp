class TimeMap {
public:
    map<string,vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int k = -1;
        int l = 0, r = mp[key].size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mp[key][mid].first <= timestamp){
                k = mid;
                l = mid+1;
            }else r = mid-1;
        }
        if(k==-1) return "";
        return mp[key][k].second;
    }
};
