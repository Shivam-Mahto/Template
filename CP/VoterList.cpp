#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    map<int,int> check;

    for(int i=0; i<n1 + n2 + n3; i++)
    {
        int num;
        cin>> num;
        check[num]++;
    }

    vector<int> ans;
    map<int, int> :: iterator it;
    for(it = check.begin(); it!= check.end(); it++)
    {
        if(it->second >= 2)
        {
            ans.push_back(it->first);
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;

}