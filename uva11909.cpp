#include<bits/stdc++.h>
const double pi=2*acos(0);
#define tan(a) tan(a*pi/180)
using namespace std;
int main()
{
    double v1,v2;
    int w,l,h,angle;
    while(scanf("%d%d%d%d",&l,&w,&h,&angle)!=EOF)
    {
        if(l*tan(angle)<=h)
        {

            v1=w*.5*l*l*tan(angle);
            v2=l*w*h-v1;
            printf("l%.3lf mL\n",v2);
        }
        else
        {
            angle=90-angle;

            printf("%.3lf mL\n",w*.5*h*h*tan(angle));
        }
    }
}
