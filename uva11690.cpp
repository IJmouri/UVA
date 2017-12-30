#include <bits/stdc++.h>
using namespace std;
int parent[10005] , ran[10005],s[10005] ;
void built (int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        ran[i] = 0;
    }
}
int make_friend (int n)
{
    if(parent[n] == n) return n;
    else return parent[n] = make_friend(parent[n]);
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
    int m , n,t,money;
    cin >> t;
    vector<int>v;
    set<int>st;
    while(t--)
    {
        cin>>n>>m;
        for(int i = 0 ; i < n; i++)
        {
            cin>>money;
            v.push_back(money);
        }
        built(n);
        for(int i = 0 ; i < m; i++)
        {
            int a, b;
            cin>>a>>b;
            int pa = make_friend(a);
            int pb = make_friend(b);

            if(pa != pb)
            {
                make_union(pa, pb);
            }
        }
        int l=0;
        set<int>::iterator it;
        for(int i = 0; i < n; i++)
        {
            int x = make_friend(i);
            st.insert(x);
            s[x]=s[x]+v[i];
        }
        for(it=st.begin(); it!=st.end() ; it++)
        {
            if(s[*it]!=0)
                l=1;
        }
        if(l==0)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
        memset(parent,0,sizeof parent);
        memset(ran,0,sizeof ran);
        memset(s,0,sizeof s);
        v.clear();
        st.clear();
    }
}
