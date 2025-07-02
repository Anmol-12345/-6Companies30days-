class Solution {
public:
//int M = 1e9+7;
// int solve(int i,int count_invalid,vector<int>& freq,int k)
// {
//     if(i>=freq.size())
//     {
//         if(count_invalid<k)
//         {
//             //matlab ek Invalid string found ho gai.
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     long long result = 0;
//     for(int take  = 1;take <= freq[i];take++)
//     {
//         if(take+count_invalid<k)//Invalid string found
//         {
//             result = (result+solve(i+1,take+count_invalid,freq,k))%M;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return result;
// }

// int solveusingMemo(int i,int count_invalid,vector<int>& freq,int& k,vector<vector<int>>& dp)
// {
//     if(i>=freq.size())
//     {
//         if(count_invalid<k)
//         {
//             //matlab ek Invalid string found ho gai.
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     if(dp[i][count_invalid]!=-1)
//     {
//         return dp[i][count_invalid];
//     }

//     long long result = 0;
//     for(int take  = 1;take <= freq[i];take++)
//     {
//         if(take+count_invalid<k)//Invalid string found
//         {
//             result = (result+solveusingMemo(i+1,count_invalid+take,freq,k,dp))%M;
//         }
//         else
//         {
//             break;
//         }
//     }
//     dp[i][count_invalid] = result;
//     return dp[i][count_invalid];
// }
    // int possibleStringCount(string word, int k) {
    //     //first we create freq array.
    //     //that stor count of each character
    //     vector<int>freq;
    //     int count = 1;
    //     for(int i = 1;i<word.size();i++)
    //     {
    //         if(word[i]==word[i-1])
    //         {
    //             count++;
    //         }

    //         else
    //         {
    //             freq.push_back(count);
    //             //reset count for next character
    //             count = 1;
    //         }
    //     }
    //     freq.push_back(count);

    //     //Here now calculate the all possiblity 
    //     int p = 1;
    //     for(auto&i:freq)
    //     {
    //         p = (1LL * p * i) % M;
    //     }

    //     //after calculating all possiblity
    //     //check some condition
    //     //agar unique chacter >= k -->return p;
    //     if(freq.size()>=k)
    //     {
    //         return p;
    //     }

    //     int count_invalid = 0;
    //     int i = 0;
    //     //Agar maano ki unique character < k tab 
    //     //we have calculate the  invalid string count.

    //     // long long InvalidCount = solve(i,count_invalid,freq,k);
    //     int n = freq.size();
    //     vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    //     // long long InvalidCount = solveusingMemo(i,count_invalid,freq,k,dp);

    //     return (p-InvalidCount+ M)%M;
    // }

    //nOW THIS IS TABULATION METHOD FOR SOLVING THIS PROBLEM 



//     int possibleStringCount(string word, int k) {
//     const int M = 1e9 + 7;

//     // Build frequency array of consecutive characters
//     vector<int> freq;
//     int count = 1;
//     for (int i = 1; i < word.size(); i++) {
//         if (word[i] == word[i - 1]) count++;
//         else {
//             freq.push_back(count);
//             count = 1;
//         }
//     }
//     freq.push_back(count);

//     int n = freq.size();

//     // Total possible combinations
//     long long total = 1;
//     for (auto f : freq) {
//         total = (total * f) % M;
//     }

//     // If already enough unique groups, return total
//     if (n >= k) return total;

//     // dp[i][c] = number of invalid strings using first i groups with c used so far
//     vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

//     // Base case: i == n
//     for (int c = 0; c < k; c++) {
//         dp[n][c] = 1; // These are invalid
//     }

//     // Build table from n-1 to 0
//     for (int i = n - 1; i >= 0; i--) {
//         for (int c = 0; c < k; c++) {
//             long long sum = 0;
//             for (int take = 1; take <= freq[i]; take++) {
//                 int new_c = c + take;
//                 if (new_c < k) {
//                     dp[i][c] = (dp[i][c] + dp[i + 1][new_c]) % M;
//                 } else {
//                     break;
//                 }
//             }
//         }
//     }

//     long long invalid = dp[0][0];
//     return (total - invalid + M) % M;
// }


int possibleStringCount(string word, int k) {
    const int M = 1e9 + 7;

    vector<int> freq;
    int count = 1;
    for (int i = 1; i < word.size(); i++) {
        if (word[i] == word[i - 1]) count++;
        else {
            freq.push_back(count);
            count = 1;
        }
    }
    freq.push_back(count);

    int n = freq.size();

    // Total possible combinations
    long long total = 1;
    for (auto f : freq) {
        total = (total * f) % M;
    }

    if (n >= k) return total;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case
    for (int c = 0; c < k; c++) {
        dp[n][c] = 1;
    }

    // Tabulate from i = n-1 to 0
    for (int i = n - 1; i >= 0; i--) {
        // Prefix sum of dp[i+1][..]
        vector<int> prefix(k + 2, 0); // k+2 for handling r+1 index
        for (int c = 0; c <= k; c++) {
            prefix[c + 1] = (prefix[c] + dp[i + 1][c]) % M;
        }

        for (int c = 0; c < k; c++) {
            int l = c + 1;
            int r = min(k - 1, c + freq[i]);
            if (l <= r) {
                dp[i][c] = (prefix[r + 1] - prefix[l] + M) % M;
            }
        }
    }

    int invalid = dp[0][0];
    return (total - invalid + M) % M;
}

 };