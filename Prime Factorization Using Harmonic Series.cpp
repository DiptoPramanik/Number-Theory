#include<bits/stdc++.h>
using namespace std;
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
const int PMX = 1e7+123;
vector<int>factors[PMX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e6;
    Sieve(lim);
    for(auto p:primes)
    {
        for(int i=p;i<=lim;i+=p)
        {
            int n = i;
            ///frequency
            while(n%p==0)
            {
                factors[i].push_back(p);
                n/=p;
            }
        }
    }
    for(int i=1;i<=30;i++)
    {
        cout<<i<<" : ";
        if(i==1) cout<<"Nai";
        for(auto u:factors[i]) cout<<u<<" ";
        cout<<'\n';
    }
    return 0;
}

