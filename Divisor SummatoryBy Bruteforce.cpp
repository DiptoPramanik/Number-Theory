#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //// Complexity O(N^2)
    int n = 5;
    int snod = 0;
    for(int i=1;i<=n;i++)
    {
        int snodI = 0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0) snodI++;
        }
        snod+=snodI;
     }
     cout<<"1 to N SNOD = "<<snod<<'\n';
    return 0;
}

