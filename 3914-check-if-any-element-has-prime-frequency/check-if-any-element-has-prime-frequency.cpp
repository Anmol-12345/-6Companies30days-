class Solution {
public:
    bool isprime(int n)
    {
        if(n<2)
        {
            return false;
        }

        for(int i =2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    return false;
                }
            }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++)
            {
                mp[nums[i]]++;
            }

        for(auto&v:mp)
            {
                int n = v.second;
                if(isprime(n))
                {
                    return true;
                }
            }
        return false;
    }
};