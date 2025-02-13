#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mx = 1e6+123;
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
ll phi[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e6;
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
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll sum = (n*(n-1))/2;
        ll sumCoPrime = (phi[n]*n)/2;
        cout<<(sum - sumCoPrime)<<'\n';
    }
    return 0;
}

