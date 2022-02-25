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

        if(a>=0&&a<m&&b>=0&&b<m&&r[a][b]==0)
        {
            r[a][b]=1;
            if(maze[a][b]=='1')
            {
                dfs(a,b);
            }
        }
    }
}
int main()
{
    int i,j,x=1;
    while(cin>>m)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>maze[i][j];
            }
        }
        memset(r,0,sizeof r);
        int c=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(r[i][j]==0)
                {
                   if(maze[i][j]=='1')
                   {
                       dfs(i,j);
                       c++;
                   }
                }
            }
        }
        cout<<"Image number "<<x++<<" contains "<<c<<" war eagles."<<endl;
    }
    return 0;
}

