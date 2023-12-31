/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
private:
    stack<NestedInteger> s;     
public:
    NestedIterator(vector<NestedInteger> &nums) 
    {
        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            s.push(nums[i]);
        }
    }
    int next() 
    {
        int result = s.top().getInteger();
        s.pop();
        return result;
    }
    
    bool hasNext() 
    {
        while (!s.empty()) 
        {
            if (s.top().isInteger())    return true;
            vector<NestedInteger> nums = s.top().getList();
            s.pop();
            for (int i = nums.size() - 1; i >= 0; i--) 
            {
                s.push(nums[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nums);
 * while (i.hasNext()) cout << i.next();
 */