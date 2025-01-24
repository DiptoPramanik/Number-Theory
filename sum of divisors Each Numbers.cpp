#include<bits/stdc++.h>
using namespace std;
const int mx =1e6+123;
int SumOfDivisors[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim = 6;
    for(int i=1;i<=lim;i++)
    {
        for(int j=i;j<=lim;j+=i)
        {
            SumOfDivisors[j]+=i;
        }
    }
    for(int i=1;i<=lim;i++)
    {
        cout<<i<<" : "<<SumOfDivisors[i]<<'\n';
    }
    return 0;
}

