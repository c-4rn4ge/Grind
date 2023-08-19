class findU
{
public:
    vector<int> parent;
    findU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findP(int p)
    {
        return parent[p] == p ? p : parent[p] = findP(parent[p]);
    }
    void Uni(int u, int v)
    {
        int pu = findP(u), pv = findP(v);
        parent[pu] = pv;
    }
};

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<int> cr, pcr;
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), cmp);
        int mst = findMST(n, edges, -1, -1);
        for (int i = 0; i < edges.size(); i++)
        {
            if (mst < findMST(n, edges, i, -1))
                cr.push_back(edges[i][3]);
            else if (mst == findMST(n, edges, -1, i))
                pcr.push_back(edges[i][3]);
        }
        return {cr, pcr};
    }

private:
    int findMST(int &n, vector<vector<int>> &edges, int block, int e)
    {
        findU uf(n);
        int weight = 0;
        if (e != -1)
        {
            weight += edges[e][2];
            uf.Uni(edges[e][0], edges[e][1]);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == block)
                continue;
            if (uf.findP(edges[i][0]) == uf.findP(edges[i][1]))
                continue;
            uf.Uni(edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }
        for (int i = 0; i < n; i++)
        {
            if (uf.findP(i) != uf.findP(0))
                return INT_MAX;
        }

        return weight;
    }
};