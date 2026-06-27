class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>>pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.rbegin(), nums.rend());
        for(int i=0;i<min((int)nums.size(), k);i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(!pq.size()){
            pq.push(val);
            return val;
        }
        if(pq.top() < val){
            if(pq.size() == k) pq.pop();
            pq.push(val);
        } 
        return pq.top();
    }
};
