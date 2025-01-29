#include<bits/stdc++.h>
using namespace std;
const int mx = 5e6+123;
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
const int MX = 5e6+123;
unsigned long long int phi[MX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 5e6;
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

    for(int i =1;i<=lim;i++)
    {
        phi[i] = (phi[i]*phi[i])+phi[i-1];
    }
    int t; cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int a,b; cin>>a>>b;
        cout<<"Case "<<tc<<": "<<(phi[b]-phi[a-1])<<'\n';
    }
    return 0;
}

