#include<bits/stdc++.h>
using namespace std;
const int mx = 1e7+123;
///bool isPrimes[mx];
bitset<mx>isPrimes;
vector<int>primes;
void PrimeGen(int n)
{
    for(int i=2;i<=n;i++) isPrimes[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i+i;j<=n;j+=i)
        {
            isPrimes[j]=0;
        }
    }
    for(int i=2;i<=n;i++)
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
    int lim=1e7;
    PrimeGen(lim);
    int x = primes.size();
    for(int i=0;i<x;i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<'\n';
    return 0;
}

