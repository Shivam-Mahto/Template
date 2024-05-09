#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // less_equal for ordered multiset
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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


struct Lazy_segmentTree {

    int n;

    vector<ll> v;
    vector<ll> lazy;
    vector<ll> segTree;

    Lazy_segmentTree(int size, vector<ll> arr) {
    
        n = size;
        v = arr;
    	lazy.resize(4*n, 0);
        segTree.resize(4*n, 0);
        build_tree(0, n-1, 1);
    }
     
    void build_tree(int start, int end, int treeIndex) {
     
        if(start == end) { segTree[treeIndex] = v[start]; return; }
     
        int mid = (start + end) / 2;
        build_tree(start, mid, treeIndex*2);
        build_tree(mid+1, end, treeIndex*2 + 1);
        
        // combine
        segTree[treeIndex] = segTree[treeIndex*2] + segTree[treeIndex*2 + 1];
    }

    void propagate(int treeIndex, int start, int end) {

        if(lazy[treeIndex] != 0) {

            segTree[treeIndex] += (end - start + 1) * lazy[treeIndex];

            if(start != end) {
                lazy[treeIndex*2] += lazy[treeIndex];
                lazy[treeIndex*2 + 1] += lazy[treeIndex];
            }

            lazy[treeIndex] = 0;
        }
    }

     
    ll range_query_tree(int start, int end, int left, int right, int treeIndex) {
     
        propagate(treeIndex, start, end);

        if(start > right || end < left) return 0;
        if(start >= left && end <= right) { return segTree[treeIndex]; }
     
        int mid = (start + end) / 2;
        ll leftAns = range_query_tree(start, mid, left, right, treeIndex*2);
        ll rightAns = range_query_tree(mid+1, end, left, right, treeIndex*2 + 1);

        // combine
        return leftAns + rightAns;
    }
     
    void update_tree(int start, int end, int left, int right, ll val, int treeIndex) {
     
        propagate(treeIndex, start, end);

        if(start > right || end < left) { return; }
        if(start >= left && end <= right) { 
            lazy[treeIndex] += val;
            propagate(treeIndex, start, end);
            return;
        }
         
        int mid = (start + end) / 2;
        update_tree(start, mid, left, right, val, treeIndex*2);
        update_tree(mid+1, end, left, right, val, treeIndex*2 + 1);
        segTree[treeIndex] = segTree[treeIndex*2] + segTree[treeIndex*2+1];     
    }


    // user functions
    // for range updates and range query
    // for range updates and point query you can use left = right;
    
    void update(int left, int right, ll val) {
        update_tree(0, n-1, left, right, val, 1);
    }

    ll query(int left, int right) {
        return range_query_tree(0, n-1, left, right, 1);
    }

};

void solve() {

    int n, q;
    cin>>n>>q;

    vector<ll> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Lazy_segmentTree s(n, arr);

    while(q--) {

        int x;
        cin>>x;

        if(x == 1) {

            int l, r, val;
            cin>>l>>r>>val;
            s.update(l-1, r-1, val);

        } else {

            int idx;
            cin>>idx;
            cout<<s.query(idx-1, idx-1)<<endl;
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
	    freopen("Error.txt", "w", stderr);
	#endif

	int t = 1;

	while(t--) {

		solve();
	}
}