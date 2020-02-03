#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int prime[20000011] , nPrime;
int mark[20000011];
int factor[3000];
int ck;
void sieve(int n)
{
    int i , j , limit = sqrt(n * 1.) + 2;
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
    for(int i = 0; prime[i] <= sqrt(n); i++)
    {
        while(n % prime[i] == 0)
        {
            factor[ck++] = prime[i];
            n = n / prime[i];
        }
    }
    if(n > 1)
    {
        factor[ck++] = n;
    }
}
int main()
{
    sieve(20000011);
    int n,n1,i,n2;
    while(cin >> n2)
    {
        if(n2==0)
            break;
            ck=0;
            printf("%d = ",n2);
        if(n2<0)
        {
            printf("-1 x ");
            n1=-n2;
        }
        else
            n1=n2;
        prime_factor(n1);
       // printf("%d x", factor[0]);
        for( i = 0; i < ck-1; i++)
        {
            printf("%d x ", factor[i]);
        }
        printf("%d\n",factor[i]);
        memset(factor,0,sizeof factor);
    }
}
