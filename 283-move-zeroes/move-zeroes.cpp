class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos =0;
        int i =0;
        while(i<=nums.size()-1)
        {
            if(nums[i]!=0)
            {
                nums[pos] = nums[i];
                pos++;
            }
            i++;
        }

        while(pos<=nums.size()-1)
        {
            nums[pos] =0;
            pos++;
        }
    }
};