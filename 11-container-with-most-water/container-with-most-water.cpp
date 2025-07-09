class Solution {
public:
    int maxArea(vector<int>& height) {
        int s =0;
        int e = height.size()-1;
        int maxWater =0;
        while(s<=e)
        {
            int w = e-s;
            int h = min(height[s],height[e]);
            int area = h*w;

            maxWater = max(maxWater,area);

            if(height[s]>height[e])
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        return maxWater;
    }
};