class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ns(n,n), ps(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ps[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ns[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i]*(ns[i]-ps[i]-1));
        }
        return ans;
    }
};
