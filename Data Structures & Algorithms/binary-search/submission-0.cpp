class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        while(s <= e) {
            long long m = s + (e - s)/2;
            if(arr[m] > target) {
                e = m-1;
            } else if(arr[m]<target) {
                s = m+1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
