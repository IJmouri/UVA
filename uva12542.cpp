#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll  prime[30000000] , nPrime;
ll mark[10000002];
ll a[1000008];
void sieve(int n)
{
    ll i , j , limit = sqrt(n * 1.) + 2;
    mark[1] = 1;
    for(ll i = 4; i <= n; i += 2)
        mark[i] = 1;
    prime[nPrime++] = 2;

    for(i = 3; i <= n; i++)
    {
        if(!mark[i])
        {
            prime[nPrime++] = i;
            if(i <= limit)
            {
                for(j = i * i; j <= n; j+= i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

int main()
{
    string s,s1;
    int i,k,l=0,j;
    sieve(1000005);

    while(cin>>s)
    {
        if(s=="0")
            break;
        l=0;
        s1="";
        for(j=0; j<s.length(); j++)
        {
            for(k=j; k<s.length(); k++)
            {
                if(k==j+6)
                    break;
                s1=s1+s[k];
                int r=0;
                for(i=0; i<s1.length(); i++)
                {
                    r=r*10+s1[i]-'0';
                }
                if(mark[r]==0&&r<=100000)
                {
                    a[l]=r;
                    l++;
                }
            }
            s1.clear();
        }
        sort(a,a+l);
        printf("%d\n",a[l-1]);
        memset(a,0,sizeof a);
    }
}

