#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
bitset<mx>isPrimes;
void sieve(int n)
{
    for(int i=3;i<=n;i+=2) isPrimes[i]=1;
    int sq = sqrt(n);
    for(int i=3;i<=sq;i+=2)
    {
        for(int j=i*i;j<=n;j+=i)
        {
            isPrimes[j]=0;
        }
    }
    isPrimes[2]=1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e5;
    sieve(lim);
    int n; cin>>n;
    if(n<=2) cout<<"1\n";
    else cout<<"2\n";
    for(int i=1;i<=n;i++)
    {
        if(isPrimes[i+1]) cout<<"1 ";
        else cout<<"2 ";
    }
    cout<<'\n';
    return 0;
}

