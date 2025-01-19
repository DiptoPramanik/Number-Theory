#include<bits/stdc++.h>
using namespace std;
const int mx = 1e7+123;
int cnt[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int limit = 1e7;
    for(int i=1;i<=limit;i++)
    {
        for(int j=i;j<=limit;j+=i)
        {
           cnt[j]++;
        }
    }
    for(int i=1;i<=limit;i++)
    {
        cout<<i<<" : "<<cnt[i]<<'\n';
    }
    return 0;
}
/*Time complexity
**(n/k)
=>n/1 + n/2 + n/3 + n/4 + n/5 + ..... + n/k
=>n(1 + 1/2 + 1/3 + 1/4 + 1/5 + ..... + 1/k
=>n*Harmonic series
=>n*summation(k=1 to n)1/k
=>n*(ln(n) + λ + 1/2*n - ε        //ε = 1/8*n*n (neglectable) && λ = 0.5772 & 1/2*n neglectable
=>n*ln(n)
*/
///O(n*ln(n))
