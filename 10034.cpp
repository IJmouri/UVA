#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 110;
int nodes, edges,a1,b1,  x1,i,j,y2, root[MAX_N];
double a[110],b[110],x,y,weight,w;
int find_root(int x2)
{
    if (root[x2] != x2) root[x2] = find_root(root[x2]);
    return root[x2];
}
int main()
{
    int t,n,c=1;
    scanf("%d",&t);
    while(t--)
    {
        c=1;

        map<pair<double, double>,int> mp;
        vector< pair<double, pair<int, int> > > E;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
            if(mp.count(make_pair(a[i],b[i]))==0)
                mp.insert(make_pair(make_pair(a[i],b[i]), c++));
        }
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                x=a[i]-a[j];
                x=x*x;
                y=b[i]-b[j];
                y=y*y;
                weight=sqrt(x+y);
                x1=mp[ {a[i],b[i]}];
                y2=mp[ {a[j],b[j]}];
                E.push_back(make_pair(weight, make_pair(x1,y2)));
            }
        }
        sort(E.begin(), E.end());
        for (int i = 1; i <= n; i++) root[i] = i;
        double totalDistance = 0;
        for (int i = 0; i < E.size(); i++)
        {
            a1 = find_root(E[i].second.first);
            b1 = find_root(E[i].second.second);
            if (a1 != b1)
            {
                totalDistance += E[i].first;
                root[a1] = root[b1];
            }
        }
        printf("%.2lf\n",totalDistance);
        if(t)
            printf("\n");
            memset(root,0,sizeof root);
    }
}
