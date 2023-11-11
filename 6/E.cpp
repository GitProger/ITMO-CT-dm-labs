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

////////////////////////////////////////////////////////////////////////////////

template <class T> T rmin(T &a, const T &b) { return (a = min(a, b)); }
template <class T> T rmax(T &a, const T &b) { return (a = max(a, b)); }
template <class T> T reql(T &a, const T &b) { return (a = b); }

inline void solve() {
    int n; cin >> n;
    vec<seti> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --v; --u;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    seti leaves;
    for (int i = 0; i < n; i++) {
        if (len(g[i]) == 1) {
            leaves.insert(i);
        }
    }
    
    veci ans;
    ans.reserve(n);
    
    while (!leaves.empty()) {
        int v = *leaves.begin();
        int u = *g[v].begin();
        ans.psh(u + 1);

        leaves.erase(leaves.begin());

        g[v].erase(u);
        g[u].erase(v);

        if (len(g[u]) == 1) {
            leaves.insert(u);
        }
    }
    ans.pop_back();
    ans.pop_back();
    cout << ans << $;
}
/*
*/ 

