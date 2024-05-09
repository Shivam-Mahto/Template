#include<iostream>
#include<algorithm>
#include<queue>
typedef long long ll;
using namespace std;
int main()
{
    int n,m;

    cin>>n>>m;

    ll input[n];
    for(int i=0; i<n; i++)
    {
        cin >> input[i];
    }

    sort(input, input+ n);

    int end = n - 1;

    queue<ll> q;
    
    int count = 0;

    for(int i=0; i<m; i++)
    {
        int t;
        cin>> t;
        
        ll ans = 0;
        
        while(count < t)
        {
            if(q.size() == 0)
            {
                ans = input[end];
                end--;
                if(ans / 2 > 0)
                {
                    q.push(ans/2);
                }
            }
            else if(end >=0 && (input[end] > q.front()))
            {
                ans = input[end];
                if(ans / 2 > 0)
                {
                    q.push(ans/2);
                }
                end--;
            }  
            else
            {
                ans = q.front();
                q.pop();
                if(ans / 2 > 0)
                {
                    q.push(ans/2);
                }
            } 
            count++; 
        }
        cout<< ans << endl;
    }

    return 0;
}