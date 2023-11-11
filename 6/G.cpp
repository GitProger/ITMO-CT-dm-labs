#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef long double ld;
typedef long long var;
typedef pair<int, int>prii;
typedef pair<ll, ll>prll;
typedef vector<int>veci;
typedef vector<ll>vecl;
typedef vector<veci> graph;
typedef map<int, int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
typedef string str;
#define vec vector
#define fir first
#define sec second
#define $ '\n' //'
#define $$ endl
#define MAX LONG_LONG_MAX
#define INF LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(o) ((int)o.size())
#define psh push_back

template <typename T> istream& operator >> (istream &in, vector<T> &v) { 
    for (T &t : v) in >> t;
    return in;
}
template <typename T> ostream& operator << (ostream &out, const vector<T> &v) {
    for (const T &t : v) out << t << ' ';
    return out;
}
template <typename T> ostream& operator << (ostream &out, const set<T> &v) {
    for (const T &t : v) out << t << ' ';
    return out;
}

template <class T> T rmin(T &a, const T &b) { return (a = min(a, b)); }
template <class T> T rmax(T &a, const T &b) { return (a = max(a, b)); }

const int MOD = 1'000'000'007;
inline void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  //  freopen("biconv.in", "r", stdin);
  //  freopen("biconv.out", "w", stdout);

    solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}

int n, m;
graph g;
veci c;

int mex(int v) {
    veci cnt(n + 1);
    for (int u : g[v])
        if (c[u] != -1)
           cnt[c[u]]++;
    for (int i = 0; i < len(cnt); i++)
        if (cnt[i] == 0)
            return i;
    return -1;
}

void dfs(int v) {
    c[v] = mex(v);
    for (int u : g[v]) {
        if (c[u] == -1) {
            dfs(u);
        }
    }
}

inline void solve() {
    cin >> n >> m;
    g.resize(n);
    c.resize(n, -1);
    for (int j = 0; j < m; ++j) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].psh(v);
        g[v].psh(u);
    }
    
    int k = 0;
    for (int i = 0; i < n; i++) rmax(k, len(g[i]));
    k += 1 - k % 2;
    dfs(0);
    cout << k << $;
    for (int e : c) cout << e + 1 << $;
}
/*

*/
