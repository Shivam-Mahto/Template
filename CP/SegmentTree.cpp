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
 
// To find the sum int the given range

struct SegmentTree{

    int n;
    vector<ll> segTree;
    vector<ll> v;

    SegmentTree(int size, vector<ll> arr) {
        n = size;
        v = arr;
        segTree.resize(4*n, 0);
        build_tree(0, n-1, 1);
    }
     
    void build_tree(int start, int end, int treeIndex) {
     
        if(start == end) { segTree[treeIndex] = v[start]; return; }
     
        int mid = (start + end) / 2;
        build_tree(start, mid, treeIndex*2);
        build_tree(mid+1, end, treeIndex*2 + 1);
     
        segTree[treeIndex] = segTree[treeIndex*2] + segTree[treeIndex*2 + 1];
    }
     
    ll query_tree(int start, int end, int left, int right, int treeIndex) {
     
        if(start >= left && end <= right) { return segTree[treeIndex]; }
        if(start > right || end < left) return 0;
     
        int mid = (start + end) / 2;
        ll leftAns = query_tree(start, mid, left, right, treeIndex*2);
        ll rightAns = query_tree(mid+1, end, left, right, treeIndex*2 + 1);

        return leftAns + rightAns;
    }
     
    void update_tree(int start, int end, int idx, ll val, int treeIndex) {
     
        if(start == end) {
            v[idx] = val;
            segTree[treeIndex] = val;
            return;
        }
     
        int mid = (start + end) / 2;
        if(idx <= mid) update_tree(start, mid, idx, val, treeIndex*2);
        else update_tree(mid+1, end, idx, val, treeIndex*2+1);

        segTree[treeIndex] = segTree[treeIndex*2] + segTree[treeIndex*2+1];
    }


    // user functions
    void update(int idx, int val) {
        update_tree(0, n-1, idx, val, 1);
    }

    ll query(int left, int right) {
        return query_tree(0, n-1, left, right, 1);
    }

};


void solve() {
    
    int n, q;
    cin>>n>>q;
    
    vector<ll> v(n, 0);
    for(int i=0; i<n; i++) { cin>>v[i]; }

    SegmentTree seg(n, v);

    while(q--) {
        ll t, a, b;
        cin>>t>>a>>b;
 
        if(t == 1) {
            seg.update(a-1, b-1);
        }
        else seg.query(a-1, b-1)<<endl;
    }
}
 
int main() {
    int t = 1;
    while(t--) {
 
        solve();
    }
}
