// class node {
//     public:
//     int x,y;
//     double d;
//     node(int x, int y, double d) {
//         this->x = x;
//         this->y = y;
//         this->d = d;
//     }
// };

// class compare {
//     public:
//     bool operator()(node* a, node* b) {
//         return a->d >b->d;
//     }
// };



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,pair<int,int> > > pq;  // max heap;

        for(int i=0;i<arr.size();i++) {
            int x = arr[i][0];
            int y = arr[i][1];
            double d = (x*x) + (y*y);
            
            // now it become kth smallest ele question
            pq.push({d,{x,y}});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ans.push_back({curr.second.first, curr.second.second});
        }
        return ans;

    }
};
