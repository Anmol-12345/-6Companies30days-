class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char ch;
        int n = s.length();

        for(int i =0;i<n;i++)
        {
            ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                {
                    if(ch==')'&&st.top()=='(')
                    {
                        st.pop();
                    }
                    else if(ch=='}'&&st.top()=='{')
                    {
                        st.pop();
                    }
                    else if(ch==']'&&st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.size()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};