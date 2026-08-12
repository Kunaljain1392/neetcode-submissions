class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i:tasks) {
            mp[i] += 1;
        }
        int cycle = 0;
        priority_queue<int> pq;
        for(auto it:mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            queue<int> q;
            for(int i=0;i<=n;i++) {
                if(!pq.empty()) {
                    int task = pq.top();
                    pq.pop();
                    task--;
                    if(task != 0) {
                        q.push(task);
                    }

                    cycle++;
                    
                } else if(!q.empty()) {
                    cycle++;
                } else {
                    break;
                }
                
            }
            while(!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }

        return cycle;

    }
};
