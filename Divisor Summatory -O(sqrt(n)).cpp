#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int snod = 0;
    int sq = sqrt(n);
    for(int i=1;i<=sq;i++)
    {
        int val = (n/i) - i;
        ///cout<<i<<" : "<<val<<'\n';
        snod+=val;
    }
    snod*=2;
    snod+=sq;
    cout<<snod<<'\n';
    return 0;
}

