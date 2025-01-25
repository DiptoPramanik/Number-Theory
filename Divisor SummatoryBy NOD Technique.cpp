#include<bits/stdc++.h>
using namespace std;
///------------------------

///Complexity =O(N*(sqrt(N)/ln(sqrt(N))))

///------------------------
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
int NOD(int n)
{
    int nod=1;
    for(auto p:primes)
    {
        if(1LL*p*p>n) break;
        if(n%p==0)
        {
            int cnt=0;
            while(n%p==0)
            {
                n/=p;
                cnt++;
            }
            cnt++;
            nod*=cnt;
        }
    }
    if(n>1)
    {
        nod*=2;
    }
    return nod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim=1e5;
    Sieve(lim);
    int n = 5;
    int snod=0;
    for(int i=1;i<=n;i++)
    {
        snod+=NOD(i);
    }
    cout<<snod<<'\n';
    return 0;
}

