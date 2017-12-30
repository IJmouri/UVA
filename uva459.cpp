#include <bits/stdc++.h>
using namespace std;
int parent[30] , ran[30],v[30] ;
void built (int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ran[i] = 0;
    }
}
bool myfn(int i, int j)
{
    return i<j;
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
    int t,m , n,co,l;
    char d,i;
    string s;
    map<char,int>mp;
    set<char>st;
    scanf("%d\n\n",&t);
    for(int tc=1;tc<=t;tc++)
    {
        cin>>d;
        getchar();
        built(26);
        co=1;
        l=0;
        for(i='A'; i<=d; i++)
            mp[i]=co++;
        while(1)
        {
            if(!getline(cin,s) || s.empty()) break;
            st.insert(s[0]);
            st.insert(s[1]);

            int pa = make_friend(mp[s[0]]);
            int pb = make_friend(mp[s[1]]);
            if(s[0]==s[1]&&v[parent[pa]]==0)
                make_union(pa, pb);
            if(pa != pb)
            {
                make_union(pa, pb);
            }
            if(ran[parent[pa]]==1&&v[parent[pa]]==0)
            {
                v[parent[pa]]=1;
                l++;
            }
            else if(ran[parent[pa]]>1)
            {
                l--;
                ran[parent[pa]]--;
            }
        }
          if(tc!=1) printf("\n");
        cout<<l+(co-1)-st.size()<<endl;
        st.clear();
        mp.clear();

        memset(v,0,sizeof v);
        memset(ran,0,sizeof ran);
        memset(parent,0,sizeof parent);
    }
}

