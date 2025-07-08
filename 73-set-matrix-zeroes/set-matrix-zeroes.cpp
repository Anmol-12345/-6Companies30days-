class Solution {
public:
void mark_row(vector<vector<int>>& matrix,int i)
{
    int col_size = matrix[0].size();//3
    for(int col =0;col<col_size;col++)
    {
       if(matrix[i][col]!=0)
       {
         matrix[i][col] = -99999; 
       }
    }
}

void mark_coll(vector<vector<int>>& matrix,int j)
{
    int row_size = matrix.size();//3
    for(int row =0;row<row_size;row++)
    {
        if(matrix[row][j]!=0)
        {
            matrix[row][j] = -99999;
        }
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        //this is row and colums
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    //found 0 element at these index
                    //set complete row make 0
                    //row is fixed.and column is varie
                    //yaha per hmme wo row number pass karna hoga jisme 0 element mila hmme.
                    mark_row(matrix,i);
                    //set complete column make 0
                    //column is fixed. and row is varie.
                    //yaha per hmme wo col number pass karna hoga jisme 0element mila hamme.
                    mark_coll(matrix,j);
                }
            }
        }
        //After marking row and column with '*' it will replace by 0 element 
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(matrix[i][j]==-99999)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};