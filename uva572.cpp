#include<bits/stdc++.h>
using namespace std;
char maze[101][101];
int r[101][101],m,n;
int fx[]={0,0,1,-1,-1,1,-1,1};
int fy[]={-1,+1,0,0,1,1,-1,-1};
void dfs(int x,int y)
{
    r[x][y]=1;

    for(int i=0;i<8;i++)
    {
        int a,b;
        a=x+fx[i];
        b=y+fy[i];

        if(a>=0&&a<m&&b>=0&&b<n&&r[a][b]==0)
        {
            r[a][b]=1;
            if(maze[a][b]=='@')
            {
                dfs(a,b);
            }
        }
    }
}
int main()
{
    int i,j;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
            break;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>maze[i][j];
            }
        }
        memset(r,0,sizeof r);
        int c=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(r[i][j]==0)
                {
                   if(maze[i][j]=='@')
                   {
                       dfs(i,j);
                       c++;
                   }
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
