#include<bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;
const int MAX_N = 200009;
int nodes, edges, a, b, weight, w,pred[MAX_N];
bool visit[MAX_N] = {0};
int main()
{
    int n,m;
    while(sf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        w=0;
        vector< pair<int, int> > adj[MAX_N];
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> weight;
            w+=weight;
            adj[a].push_back(make_pair(b, weight));
            adj[b].push_back(make_pair(a, weight));
        }
        for (int i = 0; i <m; i++)
        {
            pred[i] = -1;
            visit[i] = false;
        }
        int start = 0; /* arbitrarily pick 1 as a starting node */
        visit[start] = true;
        priority_queue< pair<int, pair<int, int> > > pq;
        for (int j = 0; j < adj[start].size(); j++)
            pq.push(make_pair(-adj[start][j].second,
                              make_pair(start, adj[start][j].first)));
        int MSTnodes = 0, totalDistance = 0;
        while (MSTnodes < m)
        {

            weight = -pq.top().first;
            a = pq.top().second.first;
            b = pq.top().second.second;
            pq.pop();
            if (visit[a] && !visit[b])
            {
                visit[b] = true;
                MSTnodes++;
                pred[b] = a;
                totalDistance += weight;
                for (int j = 0; j < adj[b].size(); j++)
                    pq.push(make_pair(-adj[b][j].second,make_pair(b, adj[b][j].first)));
            }
        }
        pf("%d\n",w-totalDistance);
        memset(pred,0,sizeof pred);
        memset(visit,0,sizeof visit);

    }
}
