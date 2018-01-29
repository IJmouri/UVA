#include<bits/stdc++.h>
const double pi=2*acos(0);
#define cosi(a)acos(a)/(pi/180)
#define sin(a)sin(a*pi/180)
using namespace std;
int main()
{
    double a,b,c,tarea,s,r1,r2,ac1,ac2,A;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3){
    s=(a+b+c)/2.0;
    tarea=sqrt(s*(s-a)*(s-b)*(s-c));
    A=cosi((b*b+c*c-a*a)/(2*b*c));
    r1=a/(sin(A)*2.0);
    ac1=pi*r1*r1-tarea;
    r2=(2*tarea)/(2*s);
    ac2=pi*r2*r2;
    printf("%.4lf %.4lf %.4lf\n",ac1,tarea-ac2,ac2);
    }
}
