class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = events.size();
        int day = events[0][0];
        int i = 0;
        int count =0;//result no of envent 
        while(!pq.empty()||i<n)
        {
            while(i<n && events[i][0]==day)
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                count++;
            }
            //one envent found 
            day++;
            //skip those event endDay<day
            while(!pq.empty() && pq.top()<day)
            {
                pq.pop();
            }
        }
        return count;
    }
};