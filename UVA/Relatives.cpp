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

ll PHI(int n)
{
    if(n==1) return 0;/// THE CORNER CASE FOR THIS PROBLEM
    ll phi = n;
    for(auto p:primes)
    {
        if(1LL*p*p>n) break;
        if(n%p==0)
        {
            while(n%p==0)
            {
                n/=p;
            }
            phi/=p;
            phi*=(p-1);
        }
    }
    if(n>1)
    {
        phi/=n;
        phi*=(n-1);
    }
    return phi;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e6;
    Sieve(lim);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        cout<<PHI(n)<<'\n';
    }
    return 0;
}



