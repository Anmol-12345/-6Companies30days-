class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int i =0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }

        int maxi = INT_MIN;
        for(auto&i:mp)
        {
            if(i.first==i.second)
            {
                maxi = max(maxi,i.first);
            }
        }
        if(maxi==INT_MIN)
        {
            return -1;
        }
        return maxi;
    }
};