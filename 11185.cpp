#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    while(cin>>n)
    {

        if(n<0)
            break;
        vector<int>v;
        if(n==0)
            cout<<"0"<<endl;
        else
        {while(n!=0)
        {
            v.push_back(n%3);
            n=n/3;

        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        printf("\n");
        v.clear();
        }
    }

}
