class Solution {
    vector<int> parent;
public:
    int findParent(int x)
    {
        if(parent[x]==x)
            return x;
        return findParent(parent[x]);
    }

    void unionFind(int x, int y)
    {
        int parentX = findParent(x);
        int parentY = findParent(y);

        if(parentX!=parentY)
        {
            if(parentX<parentY)
                parent[parentY]=parentX;
            else
                parent[parentX]=parentY;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        map<int, bool> stnStates; //track states per station
        map<int, priority_queue<int, vector<int>, greater<int>>> gridMap; //track active stations per grid in priority order
        parent.resize(c+1); //track parents per node through dsu
        
        for(int i=1; i<=c; i++)
        {
            stnStates[i]=1;
            parent[i]=i;
        }

        for(auto con: connections)
        {
            unionFind(con[0], con[1]);
        }

        for(int i=1; i<=c; i++)
        {
            int p = findParent(i);
            gridMap[p].push(i); //populate gridMap per Parent
        }

        vector<int> res;
        for(auto q: queries)
        {
            if(q[0]==2)
            {
                stnStates[q[1]]=0;
            }
            else
            {
                if(stnStates[q[1]])
                {
                    res.push_back(q[1]);
                    continue;
                }
                
                int p = findParent(q[1]);
                auto &pq = gridMap[p];
                // empty priority queue by removing offline stations
                while(!pq.empty() && !stnStates[pq.top()])
                {
                    pq.pop();
                }

                if(pq.empty())
                {
                    res.push_back(-1);
                    continue;
                }

                res.push_back(pq.top());
            }
        }

        return res;
    }
};