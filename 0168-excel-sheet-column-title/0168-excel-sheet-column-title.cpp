class Solution 
{
public:
    string convertToTitle(int c) 
    {
        string ans = "";
        while(c != 0)
        {
            char a = 'A' + (--c % 26);
            ans = a + ans;
            c /= 26;
        }
        return ans;
    }
};