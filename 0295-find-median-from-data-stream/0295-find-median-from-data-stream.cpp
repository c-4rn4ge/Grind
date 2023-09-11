class MedianFinder
{
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    MedianFinder()
    {
    }
    void addNum(int num)
    {

        if (maxh.empty() and minh.empty())  maxh.push(num);
        else
        {
            if (maxh.top() < num)   minh.push(num);
            else                    maxh.push(num);
        }
        int n = maxh.size();
        int m = minh.size();
        if (abs(n - m) == 2)
        {
            if (n > m)
            {
                int x = maxh.top();
                maxh.pop();
                minh.push(x);
            }
            else
            {
                int x = minh.top();
                minh.pop();
                maxh.push(x);
            }
        }
    }

    double findMedian()
    {
        int n = maxh.size();
        int m = minh.size();
        if ((n + m) % 2)
        {
            if (n > m)  return 1.0 * maxh.top();
            else        return 1.0 * minh.top();
        }
        else    return (double)(maxh.top() + minh.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */