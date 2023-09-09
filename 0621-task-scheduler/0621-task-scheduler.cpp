class Solution
{
public:
    int leastInterval(vector<char>& tasks, int k) 
    {
        vector<int>mp(26,0);
        int freq = 0,countFreq = 0,n = tasks.size();
        for(auto &i : tasks) freq = max(freq,++mp[i-'A']);
        for(int i = 0; i < 26; i++)
        {
            if(mp[i] == freq) countFreq++;
        }
        int time = freq + ((freq-1) * k) + countFreq - 1;
        return max(time,n);
    }
};