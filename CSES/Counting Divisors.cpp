#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6+123;
int cnt[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e6;
    /// Pre - calculation
    for(int i=1;i<=lim;i++)
    {
        for(int j=i;j<=lim;j+=i)
        {
            cnt[j]++;
        }
    }
    int q; cin>>q;
    while(q--)
    {
        int n; cin>>n;
        cout<<cnt[n]<<'\n';
    }
    return 0;
}

