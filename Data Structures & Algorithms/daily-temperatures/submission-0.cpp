class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,0);
        st.push(0);
        for(int i=1;i<arr.size();i++) {
            while(!st.empty() && arr[i]>arr[st.top()] ) {
                int temp = st.top();
                ans[temp] = i - temp;
                st.pop();
            } 
                st.push(i);
        }
        return ans;
        
    }
};
