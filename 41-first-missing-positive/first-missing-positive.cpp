class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //all bad number  replace with n+1;
        int n = nums.size();
        for(int i  =0;i<n;i++)
        {
            if(nums[i]<=0||nums[i]>n)
            {
                nums[i] = n+1;
            }
        }
        //step2->
        //mark presence of number.
        for(int i =0;i<n;i++)
        {
            int num = abs(nums[i]);
            if(num<=n)
            {
                nums[num-1] = -abs(nums[num-1]);
            }
        }
        //step3->find first missing number 
        for(int i =0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};