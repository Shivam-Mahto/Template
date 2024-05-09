#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;

        int arr[3];

		arr[0] = a;
		arr[1] = b;
		arr[2] = c;

		int flag = 0;
		
		int sum = a + b + c;
		sort(arr, arr+ 3);

		for(int i= 2; i>-1; i--)
		{
			if(arr[i] <= e)
			{
				if(sum - arr[i] <= d)
				{
					cout<<"YES"<<endl;
					flag = 1;
					break;
				}

			}

		}
		if(flag == 0)
		{
			cout<<"NO"<<endl;
		}
    }
    return 0;
}