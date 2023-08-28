class Solution {

    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    private:
    void dfs(string word, vector<string> &seq, string beginWord)
    {
        if(word == beginWord)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];
        int len = word.size();

        for(int i=0; i<len; i++)
        {
            char original = word[i];
            for(char c='a'; c<='z'; c++)
            {
                word[i] = c;
                if(mp.find(word) != mp.end() && mp[word] == steps -1)
                {
                    seq.push_back(word);
                    dfs(word, seq, beginWord);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        int len = beginWord.size();

        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            if(cur == endWord) break;
            int steps = mp[cur];
            
            for(int i=0; i<len; i++)
            {
                char original = cur[i];
                for(char c='a'; c<='z'; c++)
                {
                    cur[i] = c;
                    if(st.count(cur))
                    {
                        mp[cur] = steps+1;
                        st.erase(cur);
                        q.push(cur);
                    }
                    cur[i] = original;
                }

            }
            
        }
        if(mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord);
        }
        return ans;
    }
};