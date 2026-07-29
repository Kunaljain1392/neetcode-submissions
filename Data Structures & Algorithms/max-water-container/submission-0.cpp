class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0, j = arr.size()-1;
        int ans = 0;
        while(i<=j) {
            int b = min(arr[i],arr[j]);
            int l = j-i;
            ans = max(ans,l*b);
            if(arr[i] <= arr[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
