
class Solution {
public:
bool isprime(int n)
{
    if(n<=1)
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
int solve(int n)
{
    if(n<2)
    {
        return 0;
    }
    int count =0;
    vector<bool>nums(n,true);
    nums[0] = false;
    nums[1] = false;

    for(int i =2;i<=sqrt(n);i++)
    {
        if(nums[i]==true)
        {
            for(int j = 2;i*j<n;j++)
            {
                nums[i*j] = false;
            }
        }
    }

    for(int i = 2;i<n;i++)
    {
        if(nums[i]==true)
        {
            count++;
        }
    }
    return count;
}
    int countPrimes(int n) {
       return solve(n);
    }
};