class SeatManager
{
    int s;
    vector<int> v;
    priority_queue<int, vector<int>, greater<>> p;

public:
    SeatManager(int n)
    {
        s = 1;
        v.resize(n + 1, 0);
    }
    int reserve()
    {
        int i;v[i] = 1;
        if (!p.empty()) {i = p.top();p.pop();}
        else    i = s++;
        return i;
    }
    void unreserve(int seatNumber)
    {
        p.push(seatNumber);
        v[seatNumber] = 0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */