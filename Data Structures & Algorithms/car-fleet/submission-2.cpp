class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // phele pair bnake vector me push krdo
        if(position.size()!=speed.size()) {
            return -1;
        }
        vector<pair<int,int>> arr;
        for(int i=0;i<position.size();i++) {
            pair<int,int> pr = {position[i],speed[i]};
            arr.push_back(pr);
        }
        // phir use sort kr do 
        sort(arr.begin(),arr.end());
        stack<double> st;
        
        for(int i=arr.size()-1;i>=0;i--) {
            double currTime = (double)(target - arr[i].first)/arr[i].second;
            if(st.empty() || st.top() < currTime) {
                st.push(currTime);
            }
            // else agr peeche wali car ko km time lg rha hai to vo aage khi fleet kr jayegi 
            // to uski value vese bhi 1 hi ount krni hai to kuch mt kro 
        }
        return st.size();
    }
};
