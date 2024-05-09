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

vector<int> dis;
vector<vector<int>> up;
int n;

// to find the first parent and to find the depth of every node from the root.
void dfs(int root, vector<int> adj[], int parent, int d) {

	dis[root] = d;
	up[root][0] = parent;

	for(int i: adj[root]) {
		if(i == parent) continue;
		dfs(i, adj, root, d+1);
	}
}

// To find the 1, 2, 4, 8, 16,...... parent of every node.
void binaryLifting(int n) {

	for(int i=1; i<=ceil(log2(n)); i++) {
		for(int j=1; j<=n; j++) {
			int intermediate = up[j][i-1];
			if(intermediate != -1) {
				up[j][i] = up[intermediate][i-1];
			}
		}
	}

}

// To find the kth parent of a node using the binary representation of k.
int kthParent(int node, int k) {

	for(int i=0; i<=ceil(log2(k)); i++) {
		if((1<<i) & k) {
			node = up[node][i];
		}

		if(node == -1) break;
	}

	return node;
}

// To find the lowest common factor of two node.
int getLCA(int a, int b) {

	if(dis[a] > dis[b]) swap(a, b);

	b = kthParent(b, dis[b] - dis[a]);
	if(a == b) return a;

	for(int i=ceil(log2(n)); i>=0; i--) {

		int parenta = up[a][i];
		int parentb = up[b][i];

		if(parenta != parentb && parenta != -1 && parentb != -1) {
			a = parenta;
			b = parentb;
		}
	}

	return up[a][0];
}


void solve() {
	
	int q;
	cin>>n>>q;

	vector<int> adj[n+1];
	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	dis = vector<int> (n+1, 0);
	up = vector<vector<int>> (n+1, vector<int>(ceil(log2(n))+5, -1));

	dfs(1, adj, -1, 0);
	binaryLifting(n);

} 

int main() {
	
	int t = 1;
	fastio();
	while(t--) {

		solve();
	}
	return 0;
}
