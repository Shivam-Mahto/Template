#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        map<char, vector<int>> m;

        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]].push_back(i);
        }

        int *ans = new int[s.length()];
        int odd_count = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second.size() % 2 != 0)
            {
                odd_count++;
            }
        }

        if (odd_count > 1)
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            int i = 0, j = s.length() - 1;

            for (auto it = m.begin(); it != m.end(); it++)
            {
                if (it->second.size() % 2 == 0)
                {
                    for (int k = 0; k < it->second.size(); k = k + 2)
                    {
                        ans[i] = it->second[k];
                        ans[j] = it->second[k + 1];
                        i++;
                        j--;
                    }
                }
                else
                {
                    int startIndex = (s.length() / 2) - (it->second.size() / 2);
                    for (int l = 0; l < it->second.size(); l++)
                    {
                        ans[startIndex] = it->second[l];
                        startIndex++;
                    }
                }
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}