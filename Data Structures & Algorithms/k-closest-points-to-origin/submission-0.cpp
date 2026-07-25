class node {
    public:
    int x,y;
    double d;
    node(int x, int y, double d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b) {
        return a->d >b->d;
    }
};



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<node*, vector<node*>, compare> pq;  // min heap;

        for(int i=0;i<arr.size();i++) {
            int x = arr[i][0];
            int y = arr[i][1];
            double d = sqrt((x*x) + (y*y));
            node* temp = new node(x,y,d);
            pq.push(temp);
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k>0) {
            node* curr = pq.top();
            pq.pop();
            ans.push_back({curr->x,curr->y});
            k--;
        }
        return ans;

    }
};
