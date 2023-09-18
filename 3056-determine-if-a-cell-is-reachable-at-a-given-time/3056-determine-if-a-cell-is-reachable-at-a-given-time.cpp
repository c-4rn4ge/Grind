class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        if(sx == fx && sy == fy)  return (t != 1) ? true : false;
        int a = abs(fx - sx);
        int b = abs(fy - sy);
        if(t >= max(a,b)) return true;
        return false;
    }
};