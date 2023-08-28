class MyStack
{
public:
    queue<int> que;
    MyStack()
    {
    }
    void push(int x)
    {
        que.push(x);
    }
    int pop()
    {
        int l = que.size();
        for (int i = 0; i < l-1; i++)
        {
            int t = que.front();
            que.pop();
            que.push(t);
        }
        int r = que.front();
        que.pop();

        return r;
    }
    int top()
    {
        return que.back();
    }
    bool empty()
    {
        return que.empty();
    }
};