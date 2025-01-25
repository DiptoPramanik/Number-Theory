#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int snod=0;
    for(int i=1;i<=n;i++)
    {
        int contributionI = (n/i);
        cout<<i<<" : "<<contributionI<<'\n';
        snod+=contributionI;
    }
    cout<<snod<<'\n';
    return 0;
}

