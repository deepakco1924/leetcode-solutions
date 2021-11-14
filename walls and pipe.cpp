#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define triple pair<int,pair<int,int>>
#define MOD 1000000007
#define MOD1 998244353
#define clr(x, y) memset(x, y, sizeof(x))
#define pii pair<int, int>
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define node_pair pair<pair<int,int>,int>
#define INF 1e18
#define MINF LLONG_MIN
#define endl "\n"
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define trail_zero(x)  __builtin_clz(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// void _print(ll t) {cerr << t;}
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
template <class T>
void _print(pbds<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
const int N = 2001;
vector<pair<int, int>>adj[N];

class DSU
{
  int v;
  int *parent;
  int *rank;
public:
  DSU(int x)
  {
    this->v = x;
    rank = new int[v + 1];
    parent = new int[v + 1];
    for (int i = 0; i <= v; i++)
    {
      parent[i] = -1;
      rank[i] = 1;
    }
  }
  int find_set(int  i)
  {
    if (parent[i] == -1)
    {
      return i;
    }
    return parent[i] = find_set(parent[i]); //path compressiom
  }
  void union_set(int x, int y)
  {
    int s1 = find_set(x);
    int s2 = find_set(y);
    if (s1 != s2)
    {
      if (rank[s1] > rank[s2])
      {
        parent[s2] = s1;
        rank[s1] += rank[s2];

      }
      else {
        parent[s1] = s2;
        rank[s2] += rank[s1];

      }
    }
  }
};

void solve() {

  int n;
  cin >> n;
  vector<pair<int, int>>vec;
  vec.push_back({ -1, -1});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back({x, y});
  }
  vector<int>cost(n + 1, 0);
  vector<int>wire_cost(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> wire_cost[i];
  }
  vector<triple>edges;
  vector<vector<int>>visited(n + 1, vector<int>(n + 1, false));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (visited[i][j] == false and visited[j][i] == false and i != j) {
        int x1 = vec[i].first;
        int x2 = vec[j].first;
        int y1 = vec[i].ss;
        int y2 = vec[j].ss;
        int dist = abs(x1 - x2) + abs(y1 - y2);
        dist *= (wire_cost[i] + wire_cost[j]);
        edges.push_back({dist, {i, j}});
        visited[i][j] = true;
        visited[j][i] = false;
      }
    }


  }
  for (int i = 1; i <= n; i++) {
    int dist = cost[i];
    edges.push_back({dist, {0, i}});
    visited[i][0] = true;
    visited[0][i] = true;
  }
  int ans = 0;
  debug(edges)
  DSU g(n + 1);
  vector<int>power;
  vector<pii>conection;
  sort(all(edges));
  for (auto x : edges) {
    int w = x.first;
    int u = x.ss.ff;
    int v = x.ss.ss;
    if (g.find_set(u) != g.find_set(v)) {
      g.union_set(u, v);
      ans += w;
      if (u == 0 or v == 0) {
        if (u != 0) {
          power.push_back(u);
        }
        else {
          power.pb(v);
        }
      }
      else if (u != 0 and v != 0) {
        conection.push_back({u, v});
      }
    }
  }
  cout << ans << endl;
  cout << power.size() << endl;
  for (auto x : power)cout << x << " ";
  cout << endl;
  cout << sz(conection) << endl;
  for (auto x : conection) {
    cout << x.ff << " " << x.ss << endl;
  }

}
int32_t main() {


#ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
#endif

  fastio();
  auto start1 = high_resolution_clock::now();
  int t = 1;
  // cin >> t;
  while (t--)solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
  cerr << "Time: " << duration . count() / 1000 << endl;
#endif
  return 0;
}






