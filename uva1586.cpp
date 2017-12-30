#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,float>mp;
    mp['C']=12.01;
    mp['H']=1.008;
    mp['O']=16.00;
    mp['N']=14.01;
    int i,t,j,c=0;
    float s1=0,y;
    string s;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        getchar();
        cin>>s;
        s1=0;
        for(j=0; j<s.length(); j++)
        {
            c=0;
            if((s[j]=='C'||s[j]=='H'||s[j]=='O'||s[j]=='N')&&s.length()==1)
            {
                s1=mp[s[j]];
            }
            else
            {
                if(s[j]=='C'||s[j]=='H'||s[j]=='O'||s[j]=='N')
                {
                     if(s[j+1]=='C'||s[j+1]=='H'||s[j+1]=='O'||s[j+1]=='N')
                    {
                        y=1;
                    }
                    else if(s[j+1]>='1'&&s[j+1]<='9')
                    {
                        y=s[j+1]-'0';
                        if(s[j+2]>='1'&&s[j+2]<='9')
                        {
                            y=y*10+(s[j+2]-'0');
                            j++;
                            c++;
                        }
                        j++;
                        c++;
                    }
                    s1=s1+y*mp[s[j-c]];
                }
            }
        }
        printf("%.3f\n",s1);
    }
    return 0;
}
