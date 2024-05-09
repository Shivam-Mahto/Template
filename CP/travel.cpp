#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		vector<int> even;
		vector<int> odd;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 0)
			{
				if (i % 2 == 0)
				{
					continue;
				}
				else
				{
					even.push_back(i);
				}
			}
			else
			{
				if (i > 0 && (i % 2 != 0))
				{
					continue;
				}
				else
				{
					odd.push_back(i);
				}
			}
		}

		int size1 = even.size();
		int size2 = odd.size();
		if(size1 > size2)
		{
			for(int i=0; i<size2 ;i++)
			{
				swap(arr[even[i]], arr[odd[i]]);
			}
		}
		else
		{
			for(int i=0; i<size1 ;i++)
			{
				swap(arr[even[i]], arr[odd[i]]);
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += ((arr[i] + i + 1) % 2);
		}
		cout << sum << endl;
	}
	return 0;
}
