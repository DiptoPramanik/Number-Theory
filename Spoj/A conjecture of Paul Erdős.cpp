#include<bits/stdc++.h>
using namespace std;
const int mx = 1e7+123;
bitset<mx>isPrimes;
int cntPrime[mx];
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
    isPrimes[2]=1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 1e7;
    sieve(lim);
    int limX = 3200;
    int limY = 60;
    for(int x=1;x<=limX;x++)
    {
        for(int y=1;y<=limY;y++)
        {
            int val = ((x*x) + (y*y*y*y));
            if(val<=lim && isPrimes[val])
            {
                cntPrime[val] = 1;
            }
        }
    }
    for(int i=1;i<=lim;i++)
    {
        cntPrime[i]+=cntPrime[i-1];
    }
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cout<<cntPrime[n]<<'\n';
    }
    return 0;
}


