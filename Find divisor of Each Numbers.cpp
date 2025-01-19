#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6+123;
vector<int>divisors[mx];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int lim =1e6;
    for(int i=1;i<=lim;i++)
    {
        for(int j=i;j<=lim;j+=i)
        {
            divisors[j].push_back(i);
        }
    }

    for(int i=1;i<=lim;i++)
    {
        cout<<i<<" : ";
        for(auto u:divisors[i])
        {
            cout<<u<<" ";
        }
        cout<<'\n';
    }
    return 0;
}

