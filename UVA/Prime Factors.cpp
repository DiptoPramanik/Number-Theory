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
vector<int>primeFactors(int n)
{
    vector<int>factors;
    for(auto p:primes)
    {
        if(1LL*p*p>n) break;
        if(n%p==0)
        {
            while(n%p==0)
            {
                factors.push_back(p);
                n/=p;
            }
        }
    }
    if(n>1) factors.push_back(n);
    return factors;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim =1e7;
    Sieve(lim);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        bool isNegative = false;
        if(n<0)
        {
            isNegative = true;
            n*=-1;
        }
        vector<int>factors = primeFactors(n);
        if(isNegative)
        {
            n*=-1;
            factors.insert(factors.begin(),-1);
        }
        cout<<n<<" = "<<factors[0];
        for(int i=1;i<factors.size();i++) cout<<" x "<<factors[i];
        cout<<'\n';
    }
    return 0;
}

