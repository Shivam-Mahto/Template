#include<iostream>
#include<queue>
using namespace std;
void printMax(int* arr, int n, int k)
{
    // Make a double entry queue
    deque<int> d;

    // insert the useful element from the first k element in the queue
    for(int i=0; i<k; i++)
    {
        while((!d.empty()) && arr[i] >= arr[d.back()])
        {
            d.pop_back();
        }

        d.push_back(i);
    }

    // Now doing it for the new windows
    for(int i=k ; i < n; i++)
    {
        cout<<arr[d.front()]<<" ";

        // Removing all the indexes which are not in this window  
        while((!d.empty()) && d.front() <= i - k)
        {
            d.pop_back();
        }

        //Removing all the elements which are useless
        while((!d.empty()) && arr[i] >= arr[d.back()])
        {
            d.pop_back();
        }

        d.push_back(i);

    }
    cout<<arr[d.front()]<<endl;

}
int main()
{

    int n , k;
    cin>>n>> k;
    int* arr = new int[n];
    for(int i= 0; i<n; i++)
    {
        cin>>arr[i];
    }

    printMax(arr,n,k);
    return 0;
}