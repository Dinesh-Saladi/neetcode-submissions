class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        int cnt = 0;
        for(auto &x : piles) cnt += (x+k-1)/k;
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int l = 1, r = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(piles, h, mid)){
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
};
