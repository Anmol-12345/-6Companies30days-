class Solution {
public:
int solveusingrecursion(int amount,vector<int>& coins,int i)
{
    int n = coins.size();
    //1st base case
    if(amount==0)
    {
        return 1;
    }
    //2nd base case
    if(i==n)
    {
        return 0;
    }
    //3rd base case
    if(coins[i]>amount)
    {
        return solveusingrecursion(amount,coins,i+1);
    }

    int pick = solveusingrecursion(amount-coins[i],coins,i);
    int skip = solveusingrecursion(amount,coins,i+1);
    //here we calculate total number of ways for making amount.
    return pick+skip;
}
int solveusingMemo(int amount,vector<int>& coins,int i,vector<vector<int>>& dp)
{
    int n = coins.size();
    //one extra
    if(dp[i][amount]!=-1)
    {
        return dp[i][amount];
    }
    //1st base case
    if(amount==0)
    {
        return 1;
    }
    //2nd base case
    if(i==n)
    {
        return 0;
    }
    //3rd base case
    if(coins[i]>amount)
    {
        return solveusingMemo(amount,coins,i+1,dp);
    }

    int pick = solveusingMemo(amount-coins[i],coins,i,dp);
    int skip = solveusingMemo(amount,coins,i+1,dp);
    //here we calculate total number of ways for making amount.
    dp[i][amount] =  pick+skip;
    return dp[i][amount];
}
    int change(int amount, vector<int>& coins) {
        int i =0;
        int n = coins.size();
        // int ans = solveusingrecursion(amount,coins,i);
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solveusingMemo(amount,coins,i,dp);
        return ans;
    }
};