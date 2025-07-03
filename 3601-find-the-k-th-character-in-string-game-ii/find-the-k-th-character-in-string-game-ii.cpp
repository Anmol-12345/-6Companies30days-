class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //Base case
        if(k==1)
        {
            return 'a';
        }

        long long len = 1;
        long long newindex = -1;
        int operationtype = -1;
        int n = operations.size();
        //first we calculate the length of string in which we calculate the k th index character.

        for(int i =0;i<n;i++)
        {
            len *=2;
            if(len>=k)
            {
                operationtype = operations[i];//0,1
                newindex = (k-len/2);
                break;
            }
        }

        char ch = kthCharacter(newindex,operations);
        if(operationtype==0)
        {
            return ch;
        }
        return ch=='z'?'a':ch+1;   
    }
};