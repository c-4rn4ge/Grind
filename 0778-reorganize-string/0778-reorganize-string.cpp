class Solution
{
public:
    string reorganizeString(string s)
    {
        int h[26] = {0},maxi=-1,ind = 0;
        char c;

        for (int i = 0; i < s.length(); i++)    h[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (h[i] > maxi)
            {
                maxi = h[i];
                c = i + 'a';
            }
        }

        while (maxi > 0 && ind < s.size())
        {
            s[ind] = c;
            maxi--;
            ind += 2;
        }
        if (maxi != 0)  return "";

        h[c - 'a'] = 0;

        for (int i = 0; i < 26; i++)
        {
            while (h[i] > 0)
            {
                ind = ind >= s.size() ? 1 : ind;
                s[ind] = i + 'a';
                h[i]--;
                ind += 2;
            }
        }
        return s;
    }
};