#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
	
bool cmp(pair<pair<int,int>, int> a, pair<pair<int, int>,int> b) {

	return a.second < b.second;
}

int findParent(int node, vector<int>& rank, vector<int>& parent) {

	if(node == parent[node]) return node;

	return (parent[node] = findParent(parent[node], rank, parent));
}

void Union(int u, int v, vector<int>& rank, vector<int>& parent) {

	u = findParent(u,rank, parent);
	v = findParent(v,rank, parent);

	if(rank[u] > rank[v]) {
		parent[v] = u;
	}
	else if(rank[v] > rank[u]) {
		parent[u] = v;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}

void kruskal() {
	
	int n, e;
	cin>>n>>e;

	vector<pair<pair<int,int>, int>> adj;
	for(int i=0; i<e; i++) {

		int a, b, wt;
		cin>>a>>b>>wt;

		adj.pb({{a,b},wt});
	}	

	vector<int> rank(n, 0);
	vector<int> parent(n, 0);
	for(int i=0; i<n; i++) {
		parent[i] = i;
	}

	sort(adj.begin(), adj.end(), cmp);

	vector<pair<int,int>> mst;
	for(int i=0; i<adj.size(); i++) {

		int u = adj[i].ff.ff;
		int v = adj[i].ff.ss;

		if(findParent(u, rank, parent) != findParent(v, rank, parent)) {
			mst.push_back({u,v});
			Union(u, v, rank, parent);
		}
	}

	cout<<"The MST is: "<<nline;
	for(int i=0; i<mst.size(); i++) {
		cout<<mst[i].ff<< " - " <<mst[i].ss<<nline;
	}
} 

int main() {
	
	int t = 1;

	while(t--) {
		kruskal();
	}
	return 0;
}

// INTPUT
/*
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
7 1 11
7 8 7
2 8 2
8 6 6
2 5 4
3 5 14
*/
