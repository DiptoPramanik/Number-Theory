#include<bits/stdc++.h>
using namespace std;
const int mx = 1e7+123;
int cnt[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e7;

    ///pre-calculation
    ///O(nln(n))

    for(int i=1;i<=lim;i++)
    {
        for(int j=i;j<=lim;j+=i)
        {
            cnt[j]++;
        }
    }
    int n; cin>>n;
    long long int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(1LL*i*cnt[i]);
    }
    cout<<ans<<'\n';
    return 0;
}

