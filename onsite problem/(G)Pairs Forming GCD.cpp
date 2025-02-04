#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mx = 1e7+123;
bitset<mx>isPrimes;
vector<int>primes;
void Sieve(int n)
{
    for(int i=3;i<=n;i+=2) isPrimes[i]=1;
    int sq = sqrt(n);
    for(int i=3;i<=sq;i+=2)
    {
        if(isPrimes[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isPrimes[j]=0;
            }
        }
    }
    isPrimes[2]=1;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(isPrimes[i]==1)
        {
            primes.push_back(i);
        }
    }
}
int phi[mx];
ll preSumPhi[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e7;
    Sieve(lim);
    for(int i=1;i<=lim;i++) phi[i] = i;

    for(auto p:primes)
    {
        for(int j=p;j<=lim;j+=p)
        {
            phi[j]/=p;
            phi[j]*=(p-1);
        }
    }
    for(int i=1;i<=lim;i++)
    {
        preSumPhi[i] = preSumPhi[i-1]+phi[i];
    }
    int t; cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        ll n,p; cin>>n>>p;
        ll l=1,r=n;
        ll g = -1;
        while(l<=r)
        {
            ll  mid = (l+r)/2;
            ll x = n/mid;
            if(preSumPhi[x]>=p)
            {
                g = max(g,mid);
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<"Case "<<tc<<": "<<g<<'\n';
    }
    return 0;
}

