class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;

        //in interval based question sorting is require
        sort(intervals.begin(),intervals.end());

        result.push_back(intervals[0]);

        for(int i =1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=result.back()[1])
            {
                //overlapping
                //Merge the intervals

                //int start_pt = min(intervals[i][0],result.back()[0]);

                result.back()[1] = max(intervals[i][1],result.back()[1]);
            }

            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};