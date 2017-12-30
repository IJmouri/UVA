#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int i,t,n,c,b,j;
    for(i=1;i<=100;i++)
    {
        a[i]=i;
    }
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("Printing order for %d pages:\n",n);
        if(n%4==1)
        {
            c=2;
            b=2;
            printf("Sheet 1, front: Blank, 1\n");
        }
        else if(n%4==2)
        {
            c=3;
            b=2;
            printf("Sheet 1, front: Blank, 1\n");
            printf("Sheet 1, back: 2, Blank\n");
        }
        else if(n%4==3)
        {
            c=4;
            b=2;
            printf("Sheet 1, front: Blank, 1\n");
        }
        else
        {
            c=1;
            b=1;
        }
        for(i=c,j=b;i<=(n/2)+2;i++,j++)
        {
            if(i%4!=0)
            {
                printf("Sheet %d,front:%d, %d\n",j,a[n],a[i]);
                j--;
                n--;
            }
            else
            {
                printf("Sheet %d,back:%d, %d\n",j,a[i],a[n]);
                n--;

            }
        }
    }

}
