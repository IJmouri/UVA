#include <bits/stdc++.h>
using namespace std;
vector <int> v[1050];
int dis[1050];
int main()
{
    int n,tes,j,m;
    cin>>tes;
    for(j=1; j<=tes; j++)
    {
        cin >> m>>n;
        for(int i = 0; i < n; i++)
        {
            int x ,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int src;
        src = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            dis[src] = 0;
            int u = q.front();
            q.pop();
            for(int i = 0; i < v[u].size(); i++)
            {
                int g = v[u][i];
                if(dis[g] == 0)
                {
                    dis[g] = dis[u] + 1;
                    q.push(g);
                }
            }
        }
        int i;
        for( i = 1; i < m; i++)
            printf("%d\n", dis[i]);

        for( i=0;i<1050;i++)
            v[i].clear();
        memset(dis, 0 ,sizeof dis);
        if(tes != j)
            printf("\n");
    }
}
