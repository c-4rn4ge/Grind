class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if(n % groupSize != 0)    return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[hand[i]]++;
        sort(hand.begin(),hand.end());
        int i = 0,c = 0;
        while(i < n) 
        {
            int c1 = 0, t = hand[i];
            while(c1 < groupSize && mp.find(t)!=mp.end()) 
            {
                if(mp[t]==1) mp.erase(t);
                else mp[t]--;
                c1 ++;
                t++;
            }
            if(c1 == groupSize) c++;
            i++;
        }
        return (c == n / groupSize);
    }
};