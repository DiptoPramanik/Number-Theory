#include<bits/stdc++.h>
using namespace std;
const int mx = 1e8;
bitset<mx>isPrimes;
vector<int>primes;
void sieve(int n)
{
    for(int i=3;i<=n;i+=2) isPrimes[i] = 1;
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
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(isPrimes[i]==1)
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e8;
    sieve(lim);
    int n = primes.size();
    for(int i=0;i<n;i+=100)
    {
        cout<<primes[i]<<'\n';
    }
    return 0;
}

