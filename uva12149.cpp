#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int i,n;
    a[0]=0;
    for(i=1;i<=100;i++)
    {
        a[i]=a[i-1]+i*i;
    }
    while(scanf("%d",&n))
    {
        if (n==0)
            break;
        printf("%d\n",a[n]);
    }
}
