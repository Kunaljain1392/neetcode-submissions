class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int mx = *max_element(arr.begin(),arr.end());
        long long low = 1;
        long long high = mx;
        long long hour = 0;
        long long ans = 0;
        
        while(low <= high) {
            long long m = low + (high - low)/2;
            for(int i=0;i<arr.size();i++) {
                hour = hour + (arr[i] + m - 1)/m;
            }
            
            if(hour <= h) {
                ans = m;
                high = m-1;
            } else if(hour > h) {
                low = m+1;
            }
            hour = 0;

        }
        return ans;
    }
};
