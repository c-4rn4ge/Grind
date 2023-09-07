class Solution 
{
private:
    int solve(int i, int j, string s) 
    {
        int l = i;
        int r = j;
        while (l >= 0 && r < s.length() && s[l] == s[r])  l--,r++;
        return r - l - 1;
    }
public:
    string longestPalindrome(string s) 
    {
        int row = 0,col=0;
        for (int i = 0; i < s.length(); i++) 
        {
            int odd = solve(i, i, s);
            if (odd > col - row + 1) 
            {
                int dist = odd / 2;
                row = i - dist;
                col = i + dist;
            }
            
            int even = solve(i, i + 1, s);
            if (even > col - row + 1) 
            {
                int dist = (even / 2) - 1;
                row = i - dist;
                col = i + 1 + dist;
            }
        }

        return s.substr(row, col-row+1);
    }
};
