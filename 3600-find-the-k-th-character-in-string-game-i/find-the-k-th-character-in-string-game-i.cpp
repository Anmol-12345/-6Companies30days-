class Solution {
public:
    char kthCharacter(int k) {
        // //here we mention here the string is "a".
        // string s = "a";

        // while(s.size()<k)
        // {
        //     string t = "";
        //     for(int i =0;i<s.size();i++)
        //     {
        //         //ek extra character string mai add karna hai.
        //         t += s[i] + 1;
        //     }
        //     //aur jo final string t aai hai usse s mai add kar do.
        //     s += t;
        // }
        // //matlab isse k se ek pehle wala character chahiye.
        // return s[k-1];

        //Other Solution 
        //this is built in function already in c++.
        return 'a'+__builtin_popcount(k-1);//it means to count no of 1s in binary representation of k-1;
    }
};