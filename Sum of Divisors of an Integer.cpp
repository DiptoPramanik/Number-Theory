#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
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
long long int SOD(int n)
{
    long long int sod=1;
    for(auto p:primes)
    {
        if(1LL*p*p>n) break;
        if(n%p==0)
        {
            long long int sum=1;
            long long int a=1;
            while(n%p==0)
            {
                a*=p;
                sum+=a;
                n/=p;
            }
            sod*=sum;
        }
    }
    if(n>1) sod*=(1+n);
    return sod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e5;
    Sieve(lim);
    cout<<SOD(12)<<'\n';
    return 0;
}

