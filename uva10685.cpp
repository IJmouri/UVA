#include <bits/stdc++.h>
using namespace std;
int parent[100005] , ran[100005] , fr[100005],a[100005];
void built (int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ran[i] = 0;
        fr[i]=1;
    }
}
int make_friend (int n)
{
    if(parent[n] == n)
        return n;
    else
        return parent[n] = make_friend(parent[n]);
}
void make_union(int a , int b)
{
    if(ran[a] > ran[b])
    {
        parent[b] = a  ;
    }
    else
    {
        parent[a] = b ;
        if(ran[a] == ran[b])
            ran[b]++ ;
    }
}
int main()
{
    int m ,n,t,k,max,j;
    string s1,s2,s;
    map<string,int>mp;
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0&&n==0)
            break;
        max=0;
        for(int i = 1; i <= m; i++)
        {
            cin>>s;
            mp[s]=i;
        }
        built(m);
        for(j=1; j<=n; j++)
        {
            cin>>s1>>s2;
            int pa = make_friend(mp[s1]);
            int pb = make_friend(mp[s2]);
            if(pa!=pb)
                make_union(pa,pb);
            if(pa!=pb)
                fr[parent[pa]]=fr[pa]+fr[pb];
            if(max < fr[parent[pa]])
                max=fr[parent[pa]];
        }
        if(n==0)
            max=1;
        cout<<max<<endl;
        memset(fr,1,sizeof fr);
        memset(parent,0,sizeof parent);
        memset(ran,0,sizeof ran);
        mp.clear();
    }
}

