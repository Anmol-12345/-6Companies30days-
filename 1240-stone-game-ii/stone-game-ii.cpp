class Solution {
public:
int solve(vector<int>& piles,int i,int m,bool alice)
{
    if(i==piles.size())
    {
        return 0;
    }
    int ans = alice? INT_MIN : INT_MAX;
    int total =0;
    for(int x = 1;x<=2*m;x++)
    {
        if(i+x-1>=piles.size())
        {
            break;
        }
        total += piles[i+x-1];
        if(alice)
        {
            ans = max(ans,total+solve(piles,i+x,max(x,m),!alice));
        }
        else
        {
            ans = min(ans,solve(piles,i+x,max(x,m),!alice));
        }
    }
    return ans;
}
int solveusingMemo(vector<int>& piles,int i,int m,bool alice,vector<vector<vector<int>>>& dp)
{
    if(i==piles.size())
    {
        return 0;
    }
    if(dp[i][m][alice]!=-1)
    {
        return dp[i][m][alice];
    }
    int ans = alice? INT_MIN : INT_MAX;
    int total =0;
    for(int x = 1;x<=2*m;x++)
    {
        if(i+x-1>=piles.size())
        {
            break;
        }
        total += piles[i+x-1];
        if(alice)
        {
            ans = max(ans,total+solveusingMemo(piles,i+x,max(x,m),!alice,dp));
        }
        else
        {
            ans = min(ans,solveusingMemo(piles,i+x,max(x,m),!alice,dp));
        }
    }
    dp[i][m][alice] = ans;
    return dp[i][m][alice];
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        int res =  solveusingMemo(piles,0,1,true,dp);
        //using recursion
       //int res = solve(piles,0,1,true);,
       return res;
    }
};