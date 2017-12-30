#include <bits/stdc++.h>
using namespace std;
int parent[100005] , ran[100005] , fr[100005],a[100005];
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
    int m , n,t,k,b,c=1,d;
    scanf("%d",&t);
    string s1,s2;
    map<string,int>mp;
    for(k=1; k<=t; k++)
    {
        cin >> n ;
        int m=0,l=0;
        d=0;
        c=1;
        for(int i = 1; i <= n; i++)
        {

            cin>>s1>>s2;
            if(mp[s1]==0)
            {
                mp[s1]=c++;
                parent[mp[s1]]=mp[s1];
                ran[mp[s1]]=0;
                fr[mp[s1]]=1;
            }
            if(mp[s2]==0)
            {
                mp[s2]=c++;
                parent[mp[s2]]=mp[s2];
                ran[mp[s2]]=0;
                fr[mp[s2]]=1;
            }
            int pa = make_friend(mp[s1]);
            int pb = make_friend(mp[s2]);
            if(pa!=pb)
                make_union(pa,pb);
           if(pa!=pb)
           fr[parent[pa]]=fr[pa]+fr[pb];
           cout<<fr[parent[pa]]<<endl;
        }
        memset(fr,1,sizeof fr);
        memset(parent,0,sizeof parent);
        memset(ran,0,sizeof ran);
        mp.clear();
    }
}

