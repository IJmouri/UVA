#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int prime[100000002], nPrime;
int mark[100000002];
int factor[300];
int ck,cnt;
set<int>st;
ll lw,hi,j,k;
void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.) + 2;
    mark[1] = 1;
    for(int i = 4; i <= n; i += 2)
        mark[i] = 1;
    prime[nPrime++] = 2;

    for(i = 3; i <= n; i++)
    {
        if(mark[i] == 0)
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
void prime_factor (int n)
{
    ck = 0;
    st.clear();
    for(int i = 0; prime[i] <= sqrt(n); i++)
    {
        while(n % prime[i] == 0)
        {
            factor[ck++] = prime[i];
            st.insert(prime[i]);
            n = n / prime[i];
        }
    }
    if(n > 1)
    {
        factor[ck++] = n;
        st.insert(n);
    }
}
int main()
{
    sieve(1000000000000);
    int n;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        cnt=0;
        scanf("%lld%lld",&lw,&hi);
        for(k=lw; k<=hi; k++)
        {
            if(mark[k]==0)
            prime_factor(k);
            if(st.size()==1)
                cnt++;
        }
        printf("%d\n",cnt);
        for(int i = 0; i < ck; i++)
        {
            printf("%d ", factor[i]);
        }
        printf("\n");
    }
}
