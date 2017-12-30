
#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n,b,w,h,p,i,j,k,up;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
    {
        int min=500005;
        for(i=0;i<h;i++)
        {
            scanf("%d",&p);
            for(j=0;j<w;j++)
            {
                scanf("%d",&a[j]);
            }
            sort(a,a+w);
            up=lower_bound(a,a+w,n)-a;
            if(up!=w)
            {
                if(p*n<=b)
                {
                    if(min>p*n)
                    {
                        min=p*n;
                    }
                }
            }
        }
        if(min!=500005)
        {
            printf("%d\n",min);
        }
        else
        {
            printf("stay home\n");
        }
        memset(a,0,sizeof a);
    }
    return 0;
}
