class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>> que;
        unordered_set<string> st(wordList.begin(),wordList.end());
        que.push({beginWord,1});

        while(!que.empty())
        {
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();
            if(word == endWord) return steps;
            for(int i = 0 ; i < word.size() ; i++)
            {
                char ab = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        que.push({word,steps+1});
                    }
                }
                word[i] = ab;
            }
        }
        return 0;        
    }
};