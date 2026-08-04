class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSum = INT_MIN;
        int cs = 0;
        for(int num:nums) {
            cs = cs+num;
            mxSum = max(mxSum,cs);
            if(cs<0) {
                cs = 0;
            }
        }
        return mxSum;
    }
};
