class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(char &ch : tasks) {
            count[ch - 'A']++;
        }

        priority_queue<int> pq;

        for(int num : count) {
            if(num > 0) {
                pq.push(num);
            }
        }

        queue<pair<int, int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;

            if(pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt > 0) q.push({cnt, time + n});
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};