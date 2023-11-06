class SeatManager
{
public:
    int v[100001] = {0};
    int top, n;
    SeatManager(int n)
    {
        this->n = n;
        fill(v, v+n, 1);
        top = 1;
    }
    int reserve()
    {
        int x = top++;
        while (top < n && !v[top])  top++;
        v[x] = 0;
        return x;
    }

    void unreserve(int seatNumber)
    {
        v[seatNumber] = 1;
        if (top > seatNumber)   top = seatNumber;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */