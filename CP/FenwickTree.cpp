#include<bits/stdc++.h>
using namespace std;
 
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


/*  This uses one based indexing but when you are using the functions use zero based index
    We use one based indexing because everytime we are removing one bit from the number but 
    if we use zero based indexing it will end up in a infinte loop
*/

/*  To count inversions, assume the bit array as the freq array and store the freq of each element to 
    its corresponding index (which is nothing but the value of arr[i]) 

    and now to find the number of element which are greater/smaller than arr[i] 
    just query to their respective ranges 
*/

struct FenwickTree {

    vector<ll> bit;  // binary indexed tree
    vector<ll> prefix_sum; // This for the range updates
    int n;
    
    // constructors
    FenwickTree(int n) {

        this->n = n;
        bit.assign(n + 1, 0);
        prefix_sum.assign(n+1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }


    // for point update and range query
    
    // for point update
    void add(int idx, int delta) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // for range query
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // for the range update and point query

    void add_to_prefixSum(int idx, int delta) {

        for(++idx; idx <= n; idx += idx & -idx)
            prefix_sum[idx] += delta;
    }

    // for range update
    void range_add(int l, int r, int val) {

        add_to_prefixSum(l, val);
        add_to_prefixSum(r + 1, -val);
    }   

    // point query
    ll point_query(int idx) {
        
        ll change = 0;
        for(++idx; idx > 0; idx -= idx & -idx) {
            change += prefix_sum[idx];
        }

        return change;
    }
};

// remember you can do only one at a time i.e either
// point update and range query
// or range updates and point query

void print(int n, vector<int>& arr) {
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<nline;
}

void solve() {
    
    int n;
    cin>>n;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    print(n, arr);

    FenwickTree f(arr);


    // doing the range updates and getting the point query
    f.range_add(1, 3, 3);

    for(int i=0; i<n; i++) {
        cout<<arr[i] + f.point_query(i)<<" ";
    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {

        solve();
    }
}

/*

input
1
5
1 2 3 4 5

output

1 2 3 4 5 
5 6 7 8 9 

*/

