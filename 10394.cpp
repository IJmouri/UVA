#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
int prime[20000011] , nPrime;
int mark[20000011],c=1,v[1000011][2];

void sieve(int n)
{
    int i , j , limit = sqrt(n * 1.) + 2;
    mark[1] = 1;
    for(int i = 4; i <= n; i += 2)
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
    sieve(20000011);
    int  s=1,s1;

    while(s<2000000)
    {
        if(prime[s+1]-prime[s]==2)
        {
            v[c][0]=prime[s];
            v[c][1]=prime[s+1];
            c++;
           // cout<<c<<endl;
        }
        s+=1;
        //cout<<s;

    }
  //  cout<<s<<" "<<c;
    while(scanf("%d",&s1)==1)
    {
        cout<<"("<<v[s1][0]<<", "<<v[s1][1]<<")\n";
    }


}
