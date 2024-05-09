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

vector<int> rabin_karp(string& s, string& p) {

    int base = 31; // for lowercase = 31 and uppercase = 53
    int mod = 1e9 + 9;
    int n = s.size(), m = p.size();

   	// we are pre calculating all the powers for the string
    vector<long long> power(n); 
    power[0] = 1; 
    for (int i = 1; i < n; i++) 
        power[i] = (power[i-1] * base) % mod;

    // calulating the hash of the given string like a prefix sum array
    vector<long long> h(n , 0); 
    for (int i = 0; i < n; i++) 
        h[i] = ( (i > 0 ? h[i-1] : 0) + (s[i] - 'a' + 1) * power[i]) % mod; 

   	// calculating the hash value of the pattern
    long long hash_pattern = 0; 
    for (int i = 0; i < m; i++)
        hash_pattern = (hash_pattern + (p[i] - 'a' + 1) * power[i]) % mod; 

    // finding all occurences by rolling the hash
    vector<int> occurences;
    for (int i = 0; i + m - 1 <= n - 1 ; i++) { 
        long long cur_h = (h[i + m - 1] + mod - (i > 0 ? h[i-1] : 0)) % mod; 
        if (cur_h == hash_pattern * power[i] % mod)
            occurences.push_back(i);
    }

    return occurences;
}

void solve() {
	
	string s, p;
	cin>>s>>p;
	vector<int> occurences = rabin_karp(s, p);
	
	for(int i=0; i<occurences.size(); i++) {
		cout<<occurences[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int t;
	cin>>t;

	while(t--) {

		solve();
	}
}