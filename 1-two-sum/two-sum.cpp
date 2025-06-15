class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;

        for(int i =0;i<nums.size();i++)
        {
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        int s =0;
        int e = nums.size()-1;
        while(s<e)
        {
            if(ans[s].first+ans[e].first> target)
            {
                e--;
            }
            if(ans[s].first+ans[e].first<target)
            {
                s++;
            }
            if(ans[s].first+ans[e].first==target)
            {
                return {ans[s].second,ans[e].second};
            }
        }
        return {};
    }
};