#include<bits/stdc++.h>
using namespace std;
long long int a[55];
int main()
{
    int i,j,t,n;
    a[1]=2;
    a[2]=3;
    for(i=3;i<=51;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n%lld\n",j,a[n]);
    }
    return 0;
}
