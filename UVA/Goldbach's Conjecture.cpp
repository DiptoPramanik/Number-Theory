#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6+123;
bitset<mx>isPrimes;
vector<int>primes;
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
    int lim = 1e6;
    sieve(lim);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        bool  ok = false;
        for(auto u:primes)
        {
            if(u>n) break;
            int a = u;
            int b = n-a;
            if(isPrimes[b])
            {
                cout<<n<<" = "<<a<<" + "<<b<<'\n';
                ok =  true;
                break;

            }
        }
        if(ok==false) cout<<"Goldbach's conjecture is wrong.\n";
    }
    return 0;
}

