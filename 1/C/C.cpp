#include <bits/stdc++.h>
using namespace std;
#define int ll
//typedef __int128 int128;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> prii;
typedef pair<ll,ll> prll;
typedef vector<int> veci;
typedef vector<prii>vecp;
typedef vector<ll> vecl;
typedef vector<veci> graph;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
typedef string str;
#define vec vector
#define fir first
#define sec second
#define $ '\n'
#define MAX LONG_LONG_MAX
#define INF (LONG_LONG_MAX/2)
#define MIN LONG_LONG_MIN
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(o) ((int)o.size())
#define psh push_back
#define beg begin
#define mkp make_pair
#define deb(a) #a<<": "<<a<<"; "
#define forn(i,n) for(int i=0;i<n;i++)
template<class T>istream&operator>>(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}
template<class T>ostream&operator<<(ostream&out,const vector<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const set<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const multiset<T>&v){for(const T&t:v)out<<t<<' ';return out;}
 
template <class T> void rmin(T &a, const T &b) { a = min(a, b); }
template <class T> void rmax(T &a, const T &b) { a = max(a, b); }

constexpr int DEBUG = 0;
#define err if(DEBUG)cerr

template<class T>istream&operator>>(istream&in,pair<T, T>&t){in>>t.fir>>t.sec;return in;}

ostream&operator<<(ostream&out,prii p){out<<"{"<<p.fir<<", "<<p.sec<<"}";return out;}//debug

mt19937 rnd(1337);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
inline void solve();
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
   // cin >> t;
    while (t--) solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}

int n, k = 0; // k - input points
graph g;
vec<veci> funs;
vec<veci> cache(27, veci(1 << 10, -1));
veci leaf;

veci to_bin(int x, int n) {
    veci res;
    while (n--) {
        res.push_back(x % 2);
        x /= 2;
    }
    reverse(all(res));
    return res;
}

int to_int(const veci &b) {
    int res = 0;
    for (int x : b) res = 2 * res + x;
    return res;
}

int getbit(int x, int i) {
    return 1L & (x >> i);
}


int dfs(int v, int depth, int &md) {
    for (int u : g[v]) {
        md = max(md, dfs(u, depth + 1, md));
    }
    return depth;
}

int invoke(int v, int arg) {
    if (len(g[v]) == 0) {
        return getbit(arg, leaf[v]);
    }
    
    if (arg < len(cache[v]) && cache[v][arg] != -1) {
 //       err << "C_" << v << " ( " << to_bin(arg, len(g[v])) << ") = " << cache[v][arg]  << "\n";
        return cache[v][arg];
    }

    int inputs = 0;
    for (int u : g[v]) {
        inputs = 2 * inputs + invoke(u, arg);
    }
    
    if (inputs < len(cache[v])) cache[v][inputs] = funs[v][inputs];
   // err << "F_" << v << " ( " << to_bin(inputs, len(g[v])) << ") = " << funs[v][inputs]  << "\n";
    return funs[v][inputs];
}

inline void solve() {    
    cin >> n;
    g = graph(n);
    funs = vec<veci>(n);
    leaf = veci(n, -1);

    for (int u = 0; u < n; u++) {
        int m; cin >> m;
        if (m == 0) {
            leaf[u] = k;
            k++;
            continue;
        }
        for (int j = 0; j < m; j++) {
            int v; cin >> v; v--;
            g[u].push_back(v);
        }
        funs[u] = veci(1LL << m);
        cin >> funs[u];
    }

    for (int &e : leaf)
        if (e != -1) e = k - 1 - e;

    int max_depth = 0;
    dfs(n - 1, 0, max_depth);
    cout << max_depth << $;
    
    for (int arg = 0; arg < (1LL << k); arg++) {
//        err << to_bin(arg, k) << ": \n";
//        int x = invoke(n - 1, arg);
//        err << "Res: " << x << $;
//        err << str(20, '=') << $;
        cout << invoke(n - 1, arg);
    }
    cout << $;
}

/*
5
0
0
2 1 2
1 1 0 1
0
2 3 4
1 0 0 1

2
01011001

2: 0---+
       +--2--+--4
1: 1---+     |
             |
0: 3---------+

*/
