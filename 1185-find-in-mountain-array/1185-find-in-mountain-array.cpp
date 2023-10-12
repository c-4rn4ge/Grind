/**
 * // This is the MountainArray'l API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int k, MountainArray &nums)
    {
        int n = nums.length(), p = -1, l = 1, h = n - 2, a;
        while(l < h)
        {
            int m = l + (h - l) / 2;
            if(nums.get(m) < nums.get(m + 1))   l = m + 1;
            else    h = m;
        } 
        p = l,l = 0,h = p;  
        while(l <= h)
        {
            int m = l + (h - l) / 2;
            a = nums.get(m);
            if(a == k) return m;
            if(a > k) h = m - 1;
            else l = m + 1;
        }
        l = p; h = n - 1;
        while(l <= h)
        {
            int m = l + (h - l) / 2;
            a = nums.get(m);
            if(a == k) return m;
            if(a < k) h = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};