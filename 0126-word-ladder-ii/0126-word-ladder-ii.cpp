class Solution
{
    unordered_map<string, int> m;
    vector<vector<string>> ans;
    string b;
public:
    void dfs(string word, vector<string> &cur)
    {
        if (word == b)
        {
            reverse(cur.begin(), cur.end());
            ans.push_back(cur);
            reverse(cur.begin(), cur.end());
            return;
        }
        int steps = m[word];
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            char ab = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (m.find(word) != m.end() && m[word] + 1 == steps)
                {
                    cur.push_back(word);
                    dfs(word, cur);
                    cur.pop_back();
                }
            }
            word[i] = ab;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        st.erase(beginWord);
        m[beginWord] = 1;
        int n = beginWord.size();
        while (!q.empty())
        {
            string word = q.front();
            int step = m[word];
            q.pop();
            if (word == endWord)    break;
            for (int i = 0; i < n; i++)
            {
                char ab = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        m[word] = step + 1;
                        st.erase(word);
                        q.push(word);
                    }
                }
                word[i] = ab;
            }
        }
        if (m.find(endWord) != m.end())
        {
            vector<string> cur;
            cur.push_back(endWord);
            dfs(endWord, cur);
        }
        return ans;
    }
};