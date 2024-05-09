#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadene(int* arr, int n)
{
    ll current_max = 0;
    ll total_max = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        current_max += arr[i];
        if(current_max > total_max)
        {
            total_max = current_max;
        }
        if(current_max < 0)
        {
            current_max = 0;
        }
    }

    return total_max;
}
ll maxSumSubarray(int* arr, int n, int k)
{
    ll prefix_sum = INT_MIN;
    ll suffix_sum = INT_MIN;

    ll kadane_sum = kadene(arr,n);
    if(k == 1)
    {
        return kadane_sum;
    }

    ll current_prefixSum = 0;
    ll current_suffixSum = 0;
    for(int i = 0; i<n; i++)
    {
        current_prefixSum += arr[i];
        if(current_prefixSum > prefix_sum)
        {
            prefix_sum = current_prefixSum;
        }
    }

    ll array_sum = current_prefixSum;

    for(int i = n-1; i>=0; i--)
    {
        current_suffixSum += arr[i];
        if(current_suffixSum > suffix_sum)
        {
            suffix_sum = current_suffixSum;
        }
    }  

    ll ans;
    if(array_sum < 0)
    {
        ans = max(suffix_sum + prefix_sum , kadane_sum);
    }
    else
    {
        ans = max(suffix_sum + prefix_sum + (array_sum * (k -2)) , kadane_sum);
    }

    return ans;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int* arr = new int[n];

        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<<maxSumSubarray(arr,n,k)<<endl;
        
    }
}