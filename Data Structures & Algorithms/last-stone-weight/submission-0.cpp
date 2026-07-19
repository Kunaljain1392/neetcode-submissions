class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            if(s1 > s2) {
                pq.push(s1-s2);
            } else if(s2 > s1) {
                pq.push(s2-s1);
            }
        }
        if(pq.empty()) {
            return 0;
        }
        return pq.top();
    }
};
