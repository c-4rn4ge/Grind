class Solution 
{
public:
    string convertToTitle(int c) 
    {
        string ans = "";
        while(c != 0)
        {
            ans = (char)('A' + ( --c % 26)) + ans;
            c /= 26;
        }
        return ans;
    }
};