class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Buy at lower price
        int Buy = INT_MAX;
        int n =   prices.size();

        int maxProfit = 0;
        for(int i =0;i<n;i++)
        {
            if(prices[i]<Buy)
            {
                Buy = prices[i];
            }

            else
            {
                //agar mujhe apne Buy wale amount se more amount milta hai toh usse sell kar dege 
                //so that maximum profit would be found here.
                maxProfit = max(maxProfit,prices[i]-Buy);
            }
        }
        return maxProfit;
    }
};