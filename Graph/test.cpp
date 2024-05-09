#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue<int, vector<int>, function<bool(int, int)>> pq_func;
/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
/*--------------------------------------------------------------------------------------------------------------------------*/
bool compare1(pair<int, ll> p1, pair<int, ll> p2)
{
	return p1.ss > p2.ss;
}
int get_min_vertex(bool* visited, ll* weight, int n)
{
	//can be used if there is some problem with priority queue and the time complexity allowed is O(N^2)
	int ans = -1;
	ll min1 = 1e18 + 1;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && weight[i] < min1)
		{
			min1 = weight[i];
			ans = i;
		}
	}
	return ans;
}
void prims(vector<pair<int, ll>>* edges, int n)
{
	bool*visited = new bool[n+1]();
	int* parent = new int[n+1];
	ll*weight = new ll[n+1];
	for (int i = 0; i < n; i++)
		weight[i] = 1e18;
	parent[0] = -1;
	weight[0] = 0;
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, function<bool(pair<int, ll>, pair<int, ll>)>> pq1(compare1);
	pq1.push(mp(0, ll(0)));
	for (int i = 0; i < n - 1; i++)
	{
		//get_min_vertex which is unvisited and has minimum weight
		//getting minimum vertex can be done in LogN using priority queue
		int minVertex = pq1.top().ff;
		pq1.pop();
		while (visited[minVertex])
		{
			minVertex = pq1.top().ff;
			pq1.pop();
		}
		visited[minVertex] = true;
		//explore all the neighbours of minVertex and update accordingly
		for (int j = 1; j < edges[minVertex].size(); j++)
		{
			if (visited[edges[minVertex][j].ff])
				continue;
			if (weight[edges[minVertex][j].ff] > edges[minVertex][j].ss)
			{
				//update the current weigth of the neighbour and change its parent also
				weight[edges[minVertex][j].ff] = edges[minVertex][j].ss;
				parent[edges[minVertex][j].ff] = minVertex;
				pq1.push(mp(edges[minVertex][j].ff, weight[edges[minVertex][j].ff]));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << i << " " << parent[i] << " " << weight[i] << endl;
}
int main()
{
	fastio();
	int n, e;
	cin >> n >> e;
	vector<pair<int, ll>> *edges = new vector<pair<int, ll>>[n+1];
	//input is taken considering 0 based indexing
	//make changes accordingly
	for (int i = 0; i < e; i++)
	{
		int a, b;
		ll weight;
		cin >> a >> b >> weight;
		edges[a].pb(mp(b, weight));
		edges[b].pb(mp(a, weight));
	}
	prims(edges, n);
	return 0;
}
