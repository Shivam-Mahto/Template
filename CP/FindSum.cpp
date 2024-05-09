#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;

        int maxMin = INT_MIN;
        for(int i=0; i<=n; i++)
        {
            if((s-i <= n) && (s-i >=0))
            {
                int diff = abs(i-(s-i));
            
                if(diff > maxMin)
                {
                    maxMin = diff;
                }
            }
        }

        cout<<maxMin<<endl;
    }
}