class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;

        int row = matrix.size();
        int col = matrix[0].size();

        int total_Element = row*col;

        int start_row =0;
        int end_row = row-1;

        int start_col = 0;
        int end_col = col-1;

        int count =0;

        while(count<total_Element)
        {
            //first row print
            for(int i = start_col;count<total_Element && i<=end_col;i++)
            {
                result.push_back(matrix[start_row][i]);
                count++;
            }
            start_row++;

            //last column print
            for(int i = start_row;count<total_Element && i<=end_row;i++)
            {
                result.push_back(matrix[i][end_col]);
                count++;
            }
            end_col--;

            //last row print
            for(int i = end_col;count<total_Element && i>=start_col;i--)
            {
                result.push_back(matrix[end_row][i]);
                count++;
            }
            end_row--;

            //start coll print
            for(int i = end_row;count<total_Element && i>=start_row;i--)
            {
                result.push_back(matrix[i][start_col]);
                count++;
            }
            start_col++;
        }
         return result;
    }
};