#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector <int> node[1000];
int  dis[1000];
void bfs (int src)
{
    dis[src] = 0;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i];
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int test,n,i,j=1 , e,x,y;
    while(scanf("%d",&e)==1)
    {
        if(e==0)
            break;

        map<int , int>mp;
        int co=0;
        memset(dis, -1, sizeof dis);
        for( i = 1; i <= e; i++)
        {
            int a, b;
            scanf("%d%d",&a,&b);
            if(mp.count(a)==0)
                mp[a]=co++;
            if(mp.count(b)==0)
                mp[b]=co++;
            node[mp[a]].pb(mp[b]);
            node[mp[b]].pb(mp[a]);
        }
        while(scanf("%d%d",&x,&y)==2)
        {
            if(x==0&&y==0)
                break;
            memset(dis, -1, sizeof dis);
            bfs(mp[x]);
            int t=0;
            for(i=0; i<co; i++)
            {


                if(dis[i]==-1||dis[i]>y)
                    t++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",j++,t,x,y);
        }
        mp.clear();
        for(int k=0; k<=co; k++)
        {
            node[k].clear();
        }
    }
}
