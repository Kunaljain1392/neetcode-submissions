class Solution {
public:
    vector<int> rightSmaller(vector<int> arr) {
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = arr.size();
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> leftSmaller(vector<int> arr) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<arr.size();i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> right = rightSmaller(heights);
        vector<int> left = leftSmaller(heights);
        for(int i=0;i<heights.size();i++) {
            int l = heights[i];
            int b = right[i]-left[i]-1;
            int area = l*b;
            ans=max(ans,area);
        }
        return ans;
    }
};
